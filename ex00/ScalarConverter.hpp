#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& original);
        ScalarConverter& operator=(const ScalarConverter& original);
        static void convert(std::string type);
        ~ScalarConverter();
};