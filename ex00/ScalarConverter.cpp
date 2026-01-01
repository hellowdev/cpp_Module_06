#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
    (void)original;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
    (void)original;
    return *this;
}

int imposy(std::string str)
{
    std::string str_check;
    std::istringstream in(str);
    
    size_t first = str.find_first_not_of(" \t\n\r\v\f");
    size_t last = str.find_last_not_of(" \t\n\r\v\f");
    // std::cout << first << " F\n";
    // std::cout << last << " L\n";
    // std::cout << last - first << " calc\n";

    // std::cout << "len of str > "<< str.length() << "\n";
    // std::cout << "count > "<< (first + last + 2) - str.length() << "\n";
    in >> str_check;
    // std::cout << "len check > "<< str_check.length() - 1 << "\n";
    if (last - first == str_check.length() - 1)
        return 1;

    return 0;
}

int detectType(std::string type)
{
    if (imposy(type) == 0)
    {
        std::cout << "imposible\n";
        return 0;
    }
    if (type.length() == 1 && !std::isdigit(type[0]))
        return 1;
    std::istringstream f(type);
    f >> type;
    std::string x = type.c_str();
    size_t find = x.find_first_not_of("0123456789");
    size_t findAll = x.find_first_not_of("+-0123456789");
    size_t pos = x.find_last_of("+-");
    if (find == std::string::npos || (findAll == std::string::npos && pos == 0))
        return 2;
    
    return 0;
}

void ScalarConverter::convert(std::string type)
{
    int retType = detectType(type);
    if (retType == 1)
        std::cout << "Char: " << type[0] << '\n';
    else if (retType == 2)
    {
        int typeInt = atoi(type.c_str());
        if ()
        std::cout << typeInt << '\n';
    }

}

ScalarConverter::~ScalarConverter(){}