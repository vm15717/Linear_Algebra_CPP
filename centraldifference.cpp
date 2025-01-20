#include <iostream>
#include <iomanip>

double exp2(double );
double rightdiff(double (*f)(double), double, double);
double prodfunc(double );

int main()
{
    double a = 1.0;
    double h = 1e-5;
    double adiff = rightdiff(exp2, a, h);
    double b = 0.1;
    double bdiff = rightdiff(prodfunc, b, h);
    std::cout << std::setprecision(17) << adiff << std::endl;
    std::cout << std::setprecision(17) << bdiff << std::endl;
    return 0;
}

double exp2(double x)
{
    return std::exp(x);
}

double rightdiff(double (*f)(double), double x, double h)
{
    return (f(x+h)-f(x-h))/(2*h);
}

double prodfunc(double x)
{
    double res = 1;
    for (int i = 1; i <= 1000; i++)
    {
        res = res * (x/i - 1);
    }
    return res;
}