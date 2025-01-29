#include <iostream>
#include <cstdint>

int main(void)
{
    uint8_t i = 2;
    uint16_t j = 256;
    uint32_t k = 51241242;
    uint64_t l = 214312421423423535;
    std::cout << (int) i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    std::cout << l << std::endl;
    return 0;
}