#include <iostream>

double exp2(double );
double trapezium(double (*f)(double), double);
int main()
{
    int num = 1000000;
    double a = 0;
    double b = 1;
    double dx = (b-a)/(double) num;
    double result = 0;
    result += trapezium(exp2, 0)/2;
    result += trapezium(exp2, 1)/2;
    for (int i = 1; i < num - 1; i++)
    {
        result += trapezium(exp2, a+i*dx);
    }
    std::cout << "The integral is : " << result/num << std::endl;
    return 0;
}

double trapezium(double (*f)(double), double x)
{
    return f(x);
}

double exp2(double x)
{
    return std::exp(x);
}