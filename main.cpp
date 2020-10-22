// Created by Daniil Rybakov IU8-33 

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <utility>


double Func(double &x) { // унимодальная ф-ия

   return x * x * sin(x);
    //return (1-x) * (1-x) + exp(x);
}

double UnimodalnayaFunc(double& x) { // мультимодальная ф-ия
    return  x * x * sin(x) * sin(5 * x);
}

void HeaderTable() {
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "|  q/P  |  0.9  | 0.91  |  0.92 |  0.93 |  0.94 | 0.95  | 0.96  | 0.97  | 0.98  | 0.99  |" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    
}

void FooterTable() {
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}




void PrintTableN(std::vector<double> const &q,
     const std::vector<double> &P, std::vector<int> &countN) {

    HeaderTable();

    for (size_t i = 0; i < q.size(); i++) { // передается q и P

        std::cout << "|" << std::right << std::setw(7) << q[i];


        for (size_t j = 0; j < P.size(); j++)
        {

         int  N = (log(1 - P[j])) / (log(1 - q[i]));

            countN.push_back(N);

            std::cout << "|" << std::right << std::setw(7) << N;

        }

        std::cout << std::endl;

    }

    FooterTable();


}


void PrintTableMinXForFunc(std::vector<double> const &q,
      const std::vector<double> &P, std::vector<int>& countN,
               std::vector<std::pair<double, double>>  &points) { // x, q, P, countN, points
   
    const double rc = 1000.0;
    const int rd = 1000;
    const int a = 9; // начальная точка
    const int b = 12; // конечная точки
    HeaderTable();

    for (int i = 0; i < q.size(); ++i) {

        std::cout << "|" << std::right << std::setw(7) << q[i];

        for (int j = 0; j < P.size(); ++j) {

            for (int n = 0; n < countN[n]; ++n)
            {

                double xi = ((rand() % ((b - a) * rd)) / rc) + a;
                double yi = Func(xi);
                std::pair<double, double> point(xi, yi);
                points.push_back(point);
            }

            auto xmin = min_element(
                points.begin(), points.end(),
                [](std::pair<double, double> l, std::pair<double, double> r) {
                return l.second < r.second; });
                std::cout << "|" << std::right << std::setw(7) << xmin->first;
                points.clear();

        }

        std::cout << std::endl;



    }

    FooterTable();

}


void PrintTableMinForUnimodalnayaFunc(std::vector<double> const &q,
    const std::vector<double> &P, std::vector<int>& countN,
    std::vector<std::pair<double, double>>& points) { // x, q, P, countN, points

    const double rc = 1000.0;
    const int rd = 1000;
    const int a = 9; // начальная точка
    const int b = 12; // конечная точки
    HeaderTable();

    for (int i = 0; i < q.size(); ++i) {

        std::cout << "|" << std::right << std::setw(7) << q[i];

        for (int j = 0; j < P.size(); ++j) {

            for (int n = 0; n < countN[n]; ++n)
            {

                double xi = ((rand() % ((b - a) * rd)) / rc) + a;
                double yi = UnimodalnayaFunc(xi);
                std::pair<double, double> point(xi, yi);
                points.push_back(point);
            }

            auto xmin = min_element(
                points.begin(), points.end(),
                [](std::pair<double, double> l, std::pair<double, double> r) {
                return l.second < r.second; });
            std::cout << "|" << std::right << std::setw(7) << xmin->first;
            points.clear();

        }

        std::cout << std::endl;



    }

    FooterTable();

}





int main() 
   {

   
    std::vector<std::pair<double, double>>  points = {};
    std::vector<int> countN = {};
    std::vector<double> P = { 0.9,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99};
    std::vector<double> q = { 0.005,0.010,0.015,0.020,0.025,0.03,0.035,0.04,0.045,0.05,
                              0.055,0.06,0.065,0.07,0.075,0.08,0.085,0.09,0.095,0.1};
    
        PrintTableN(q, P, countN);
        PrintTableMinXForFunc(q, P, countN, points); // параметры ф-ии - q, P, countN, points;
        PrintTableMinForUnimodalnayaFunc(q, P, countN, points);
        
    

    system("pause");
    return 0;

}