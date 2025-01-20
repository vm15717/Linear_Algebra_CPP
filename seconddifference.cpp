#include <iostream>
#include <iomanip>

double seconddiff(double (*f)(double), double, double);
double exp2(double);

int main()
{
    double a = 1.0;
    double h = 1e-5;
    double expdiff = seconddiff(exp2, a, h)/std::pow(h, 2);
    std::cout << std::setprecision(17) << expdiff << std::endl;
    return 0;
}

double exp2(double x)
{
    return std::exp(x);
}

double seconddiff(double (*f)(double), double x, double h)
{
    return f(x+h)-2*f(x)+f(x-h);
}