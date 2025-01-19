#include <iostream>
#include <cmath>

double rectangular(double (*f)(double), double x);
double exp2(double);

int main()
{
    std::cout << "Rectangular rule: " << std::endl;
    int num = 1000001;
    std::vector <double> result(num, 0.0);
    int a = 0;
    int b = 1;
    double dx = (b - a) /(double) num;
    for (int i = 1; i <= num; i++)
    {
        result[i] = result[i-1] + rectangular(exp2, a + dx * i) * dx;
    }
    for (int j = 0; j <= num; j += num/100)
    {
        std::cout << j << "th step : " << result[j] << std::endl;
    }
    return 0;
}

double exp2(double x)
{
    return std::exp(x);
}

double rectangular(double (*f)(double), double x)
{
    return f(x);
}