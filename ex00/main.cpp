#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "wrong Arg\n";
        return 1;
    }
    ScalarConverter::convert(av[1]);

    
    // std::string b(c);
//    std::string str = "   hello   ";
//     std::istringstream iss(str);
//     // std::string word;
//     iss >> str;
//     std::cout << str;

}