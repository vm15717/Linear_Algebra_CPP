#include "interval.cpp"

int main(void)
{
    Interval I1(1.12, 2.12);
    Interval I2(3.14, 4.13);
    std::cout << I1 << std::endl;
    std::cout << I2 << std::endl;
    Interval I3 = I1*I2;
    std::cout << I3 << std::endl;
    return 0;
}