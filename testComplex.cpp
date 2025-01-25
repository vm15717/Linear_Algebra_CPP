#include "complexnumbers.cpp"

int main()
{
    Complex c1(1.0, 1.0);
    Complex c2(1.0, -1.0);
    std::cout << c1*c2 << std::endl;
    std::cout << c1/c2 << std::endl;
    return 0;
}