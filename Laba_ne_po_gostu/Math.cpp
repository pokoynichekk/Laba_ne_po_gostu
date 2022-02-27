#include "Math.h"
#include <iostream>
#include <cmath>

const double PI = 3.14;

Math::Math()
{
	Xmin = -2.80;
	Xmax = 2.80;
	h = 0.05;
}


Math::~Math()
{

}


void Math::FindPoints()
{
    double xmin = Math::Xmin;
    double xmax = Math::Xmax;
    double h = Math::h;
    double rez;
    int counter = 1;
    std::cout << "[" << xmin << ", ";
    while (xmin < (xmax - h))
    {
        rez = xmin - 4 * (sin(xmin)) - 1;
        xmin += h;
        if (rez > -0.09 && rez < 0.09)
        {
            counter++;
            if (counter == 2)
            {
                std::cout << xmin - h << "]" << std::endl;
                counter = 0;
            }
            else
            {
                std::cout << "[" << xmin << ", ";
            }
        }
    }
}


void Math::Find()
{
    double xmin = Math::Xmin;
    double xmax = Math::Xmax;
    double h = Math::h;
    double rez;
    while (xmin < (xmax))
    {
        std::cout << "x = " << xmin;
        rez = xmin - 4 * (sin(xmin)) - 1;
        xmin += h;
        std::cout << "    f(x) = " << rez << std::endl;
    }


}


double Math::NewtonsMethod(double x, double eps)
{
    double f, df; int iter = 0;
    std::cout << "x0= " << x << " ";
    do {
        f = x - 4 * (sin(x)) - 1;
        df = 1 - 4 * (cos(x));
        x = x - f / df;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    std::cout << iter << " iterations" << std::endl;
    return x;
}


double Math::SecantMethod(double x0, double x1, double eps)
{
    double rez = x1, f0, f;
    int iter = 0;
    std::cout << "x0= " << x0 << " x1= " << x1 << " ";
    do {
        f = rez - 4 * (sin(rez)) - 1;
        f0 = x0 - 4 * (sin(x0)) - 1;
        rez = rez - f / (f - f0) * (rez - x0);
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    std::cout << iter << " iterations" << std::endl;
    return rez;
}


double Math::DichotomyMethod(double x0, double x1, double eps)
{
    double left = x0, right = x1, x, fl, fr, f;
    int iter = 0;
    std::cout << "x0= " << x0 << " x1= " << x1 << " ";
    do {
        x = (left + right) / 2;
        f = x - 4 * (sin(x)) - 1;
        if (f > 0) right = x;
        else left = x;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    std::cout << iter << " iterations" << std::endl;
    return x;
}


double Math::IterationMethod(double x, double eps)
{
    double rez; int iter = 0;
    std::cout << "x0= " << x << " ";
    do {
        rez = x;
        x = 1 + 4 * (sin(x));
        iter++;
    } while (fabs(rez - x) > eps && iter < 20000);
    std::cout << iter << " iterations" << std::endl;
    return x;
}

