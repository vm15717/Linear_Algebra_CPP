#include <iostream>
#include "vector.h"

using namespace std;
int main(void)
{
    cout << "Vector class testing...." << endl;
    cout << "------------------------" << endl;
    double simple_data[6] = {4,5,6,1,2,23};
    Vector<double> test_vector(6, simple_data);
    // test print function 
    cout << "Testing printing...." << endl;
    test_vector.printVector();
    cout << "------------------------" << endl;
    // test the vector norm function 
    cout << "Testing norm......" << endl;
    cout << test_vector.norm() << endl;
    cout << "------------------------" << endl;
    // test the normalise function
    cout << "Testing normalise....." << endl;
    test_vector.normalise();
    test_vector.printVector();
    cout << "------------------------" << endl;
    // test vector addition
    cout << "Testing vector addition....." << endl;
    double simple_data2[6] = {1,2,3,3,4,6};
    Vector<double> test_vector2(6, simple_data2);
    Vector<double> test_vector3 = test_vector + test_vector2;
    test_vector3.printVector();
    test_vector3.printVector();
    cout << "------------------------" << endl;
    // test scalar multiplication
    cout << "Testing scalar multiplication....." << endl;
    double lambda = 6;
    Vector<double> test_vector4 = test_vector3 * lambda;
    test_vector4.printVector();
    cout << "------------------------" << endl;
    // test vector subtraction
    cout << "Testing vector subtraction......" << endl;
    double simple_data3[6] = {6,4,3,3,4,6};
    Vector<double> test_vector5(6, simple_data3);
    Vector<double> test_vector6 = test_vector5 - test_vector2;
    test_vector6.printVector();
    cout << "------------------------" << endl;
    return 0;
}