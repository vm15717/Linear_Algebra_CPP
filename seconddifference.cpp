#include <iostream>
#include <iomanip>

double seconddiff(double (*f)(double), double, double);
double exp2(double);
double sqrt2(double);
double sin2(double);
int main()
{
    double a = 1.5;
    double h = 1e-7;
    double b = 31;
    double expdiff = seconddiff(exp2, a, h)/std::pow(h, 2);
    std::cout << std::setprecision(17) << expdiff << std::endl;
    double sqrtdiff = seconddiff(sqrt2, b, h)/std::pow(h, 2);
    std::cout << std::setprecision(17) << sqrtdiff << std::endl;
    double sindiff = seconddiff(sin2, b, h)/std::pow(h, 2);
    std::cout << std::setprecision(17) << sindiff << std::endl;
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

double sqrt2(double x)
{
    return std::sqrt(x);
}

double sin2(double x)
{
    return std::sin(x);
}