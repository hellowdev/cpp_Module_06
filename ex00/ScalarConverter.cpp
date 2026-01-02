#include "ScalarConverter.hpp"

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
int check_duplicate(std::string type, std::string occur)
{
    size_t firstOcc = type.find_first_of(occur);
    
    size_t secOcc = type.find_last_of(occur);
    std::cout << "first " << firstOcc << '\n';
    std::cout << "sec " << secOcc << '\n';
    if ((firstOcc && !secOcc) || (secOcc && !firstOcc && type[0] != occur[0]) \
    || (firstOcc == secOcc && type[0] != occur[0] && \
     type[type.length() - 1] != type[firstOcc] && type[type.length() - 1] != type[secOcc]))
        return 1;
    return 0;

}
int detectType(std::string type)
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
    if (check_duplicate(str, ".") && type[type.length() - 1] == 'f')
    {
        std::cout << "Iam Float\n";
        return 3;
    }
    
    return 0;
}

void ScalarConverter::convert(std::string type)
{
    int retType = detectType(type);
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
        if ((typeInt >= 0 && typeInt <= 31) || typeInt == 127)
            std::cout << "Char: Non displayable\n";
        else if (typeInt < 0 || typeInt > 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "Char: '" << static_cast<char>(typeInt) << "'\n";
    /******************INT_TYPE**************/
        if (val < INT_MIN || val > INT_MAX || errno == ERANGE  /* || end_ptr */)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << typeInt << '\n';
    }
    // else if (retType == 3)
    // {
    //     std::cout << "Iam Float\n";
    // }

}

ScalarConverter::~ScalarConverter(){}