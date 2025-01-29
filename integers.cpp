#include <iostream>
#include <cstdint>
#include <bitset>
int main(void)
{
    uint8_t i = 31;
    uint16_t j = 256;
    uint32_t k = 51241242;
    uint64_t l = 214312421423423535;
    std::cout << (int) i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    std::cout << l << std::endl;
    std::cout << std::bitset <8> (i) << std::endl;
    std::cout << std::bitset <16> (j) << std::endl;
    std::cout << std::bitset <32> (k) << std::endl;
    std::cout << std::bitset <64> (l) << std::endl; 
    int m = -31;
    std::cout << std::bitset <8> (m) << std::endl;
    return 0;
}