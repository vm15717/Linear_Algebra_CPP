#include "dualnumbers.cpp"
#include <iomanip>
double newton_raphson(double (*f)(double), double (*df)(double), double, int);
double diffsquareroot(double);
double squareroot(double);

int main()
{
    double val = newton_raphson(squareroot, diffsquareroot, 2, 10);
    std::cout << "The solution to x^2 = 2 is " << std::setprecision(17) << val << std::endl;
    return 0;
}

double newton_raphson(double (*f)(double), double (*df)(double), double init, int iter) {
    Dual res(init, 1.0);  
    for (int j = 0; j < iter; j++) {
        Dual f_val = res.apply(f, df); 
        res = res - Dual(f_val.geta(), 0.0) / Dual(f_val.getb(), 0.0);  
    }
    return res.geta(); 
}

double squareroot(double x)
{
    return x*x - 2.0;
}

double diffsquareroot(double x)
{
    return 2*x;
}