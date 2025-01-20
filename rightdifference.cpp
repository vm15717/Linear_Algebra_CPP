#include <iostream>
#include <iomanip>

double exp2(double );
double rightdiff(double (*f)(double), double, double);

int main()
{
    double a = 1.0;
    double h = 1e-5;
    double adiff = rightdiff(exp2, a, h);
    std::cout << std::setprecision(17) << adiff << std::endl;
    return 0;
}

double exp2(double x)
{
    return std::exp(x);
}

double rightdiff(double (*f)(double), double x, double h)
{
    return (f(x+h)-f(x))/h;
}