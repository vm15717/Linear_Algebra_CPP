#include <iostream>
#include "vector.h"

using namespace std;
int main(void)
{
    std::cout << "Vector testing...." << endl;
    double simple_data[6] = {4,5,6,1,2,23};
    Vector<double> test_vector(6, simple_data);
    // test print function 
    test_vector.printVector();
    cout << endl;
    // test the vector norm function 
    cout << test_vector.norm() << endl;
    // test the normalise function
    test_vector.normalise();
    test_vector.printVector();
    // test vector addition
    double simple_data2[6] = {1,2,3,3,4,6};
    Vector<double> test_vector2(6, simple_data2);
    Vector<double> test_vector3 = test_vector + test_vector2;
    test_vector3.printVector();
    test_vector3.printVector();
    // test scalar multiplication
    double lambda = 6;
    Vector<double> test_vector4 = test_vector3 * lambda;
    test_vector4.printVector();
    // test vector subtraction
    double simple_data3[6] = {6,4,3,3,4,6};
    Vector<double> test_vector5(6, simple_data3);
    Vector<double> test_vector6 = test_vector5 - test_vector2;
    test_vector6.printVector();
    return 0;
}