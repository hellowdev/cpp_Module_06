#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "wrong Arg\n";
        return 1;
    }
    ScalarConverter::convert(av[1]);
    
    // float pi = std::numeric_limits<float>::max();
    // std::cout << pi << '\n';
    // std::cout << std::fixed << std::setprecision(1) << pi << std::endl; // Output: 3.14
    return 0;


}