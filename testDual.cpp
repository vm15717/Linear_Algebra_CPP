#include "dualnumbers.cpp"
#include <cmath>

int main()
{
    Dual d(3, 1);
    Dual d1(0, 2);
    Dual d2(0, 3);
    std::cout << d.apply(std::sin, std::cos) << std::endl;
    std::cout << d1/d2 << std::endl;
    std::cout << sin(d) << std::endl;
    std::cout << pow(d, 2) << std::endl;
    return 0;
}