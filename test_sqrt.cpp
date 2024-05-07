#include <iostream>
#include <iomanip>
#include "mysqrt.cpp"

using namespace std;

 int main(void)
 {
    double num1 = 234;
    double sqrt1 = mysqrt <double>(num1);
    cout << "The square root of "<< num1 << " is " << std::setprecision(15) << sqrt1;
    return 0;
 }