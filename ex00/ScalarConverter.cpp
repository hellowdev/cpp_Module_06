#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
    (void)original;
}
void allImposi()
{
    std::cout << "char: impossible\n" << "int: impossible\n" \
    << "float: impossible\n" << "double: impossible\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
    (void)original;
    return *this;
}

int imposy(std::string str)
{
    std::istringstream in(str);

    size_t first = str.find_first_not_of(" \t\n\r\v\f");
    size_t last = str.find_last_not_of(" \t\n\r\v\f");
    in >> str;
    if (last - first == str.length() - 1)
        return 1;
    return 0;
}
int check_float(std::string type, float *myFloat)
{
    char *ptr;
    float toFloat = strtof(type.c_str(), &ptr);

    if (ptr[0] == 'f' && !ptr[1] && type.find_first_of(".") != std::string::npos)
    {
        *myFloat = toFloat;
        return 1;
    }
    return 0;
}
int detectType(std::string type, bool *check_dot, float *myFloat)
{
    if (imposy(type) == 0)
        return 0;
    if (type.length() == 1 && !std::isdigit(type[0]))
        return 1;
    std::istringstream f(type);
    f >> type;
    std::string str = type.c_str();
    size_t find = str.find_first_not_of("0123456789");
    size_t findAll = str.find_first_not_of("+-0123456789");
    size_t pos = str.find_last_of("+-");
    if (find == std::string::npos || (findAll == std::string::npos && pos == 0))
        return 2;
    if (check_float(type, myFloat))
    {   
        if (type[type.length() - 2] == '.' /*|| type[type.length() - 2] == '0'*/)
            *check_dot = true;
        return 3;
    }
    
    return 0;
}
void print_char(int type, int iType, float fType)
{
    if (type == 2)
    {
        if ((iType >= 0 && iType <= 31) || iType == 127)
            std::cout << "Char: Non displayable\n";
        else if (iType < 0 || iType > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "Char: '" << static_cast<char>(iType) << "'\n";
    }
    else if (type == 3)
    {
        if ((fType >= 0 && fType <= 31) || fType == 127)
            std::cout << "Char: Non displayable\n";
        else if (fType < 0 || fType > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "Char: '" << static_cast<char>(fType) << "'\n";
    }
    
}
void ScalarConverter::convert(std::string type)
{
    bool check_dot = 0;
    float myFloat = 0;
    int retType = detectType(type, &check_dot, &myFloat);
    char* end_ptr;
    errno = 0;

    long val = std::strtol(type.c_str(), &end_ptr, 10);
    if (retType == 0)
    {
        allImposi();
        return ;
    }
    if (retType == 1)
        std::cout << "Char: " << type[0] << '\n';
    else if (retType == 2)
    {
        int typeInt = atoi(type.c_str());
    /******************CHAR_TYPE**************/
        print_char(retType, typeInt, myFloat);
    /******************INT_TYPE**************/
        if (val < INT_MIN || val > INT_MAX || errno == ERANGE)
        {
            std::cout << "int: impossible\n";
            std::cout << "float: " << static_cast<float>(typeInt) << "f" << '\n';
            
        }
        else
        {
            std::cout << "int: " << typeInt << '\n';
            if (type.length() >= 7)
                std::cout << "float: " << static_cast<float>(typeInt) << "f" << '\n';
            else
                std::cout << "float: " << static_cast<float>(typeInt) << ".0f" << '\n';
        }
    }
    /******************FLOAT_TYPE**************/
    
    if (retType == 3)
    {
        
        // std::cout << std::fixed << std::setprecision(1);
        print_char(retType, 0, myFloat);
        std::cout << "int: " << static_cast<int>(myFloat) << '\n';
        if (type.length() >= 8 || type[type.find_first_of(".") + 1] != 'f')
            std::cout << "float: " << myFloat << "f\n";
        else if (check_dot && type.find_first_of(".") <= 6)
            std::cout << "float: " << myFloat << ".0f\n";

        // if (check_dot && type.find_first_of(".") != std::string::npos && type.find_first_of(".") <= 6)
        //     std::cout << "float: " << myFloat << ".0f\n";
        // std::cout << "float: " << myFloat << "f\n";
        // else if (!check_dot)
        //     std::cout << "float: " << myFloat << "f\n";
    }

}

ScalarConverter::~ScalarConverter(){}