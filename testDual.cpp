#include "dualnumbers.cpp"
#include <cmath>

int main()
{
    Dual d(1, 3);
    std::cout << d.apply(std::sin) << std::endl;
    return 0;
}