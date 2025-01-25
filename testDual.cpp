#include "dualnumbers.cpp"
#include <cmath>

int main()
{
    Dual d(3, 1);
    std::cout << d.apply(std::sin, std::cos) << std::endl;
    return 0;
}