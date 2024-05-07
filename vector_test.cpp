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
    return 0;
}