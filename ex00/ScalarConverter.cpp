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

void allImposi()
{
	std::cout << "char: impossible\n" << "int: impossible\n" \
	<< "float: impossible\n" << "double: impossible\n";
}

int check_nano(std::string type)
{
	if (type == "nan" || type == "nanf" || type == "+inf" || type == "-inf" || type == "+inff" || type == "-inff")
	{
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		if (type == "nan" || type == "nanf")
		{
			std::cout << "float: nanf" << '\n';
			std::cout << "double: nan" << '\n';
		}
		if (type == "+inf" || type == "+inff")
		{
			std::cout << "float: +inff" << '\n';
			std::cout << "double: +inf" << '\n';
		}
		if (type == "-inf" || type == "-inff")
		{
			std::cout << "float: -inff" << '\n';
			std::cout << "double: -inf" << '\n';
		}
		return 1;
	}
	return 0;
}
int imposy(std::string &str)
{
	std::istringstream in(str);
	std::string tmp;
	
	size_t first = str.find_first_not_of(" \t\n\r\v\f");
	size_t last = str.find_last_not_of(" \t\n\r\v\f");
	in >> tmp;
	if (last - first == tmp.length() - 1)
	{
		str = tmp;
		return 1;
	}
	return 0;
}
void print_char(int iType)
{
 	if ((iType >= 0 && iType <= 31) || iType == 127)
 		std::cout << "Char: Non displayable\n";
 	else if (iType < 0 || iType > 127)
 		std::cout << "char: impossible\n";
 	else
 		std::cout << "Char: '" << static_cast<char>(iType) << "'\n";
}
int check_dbft(std::string type, double *myDb)
{
	char *ptr;

	*myDb = std::strtod(type.c_str(), &ptr);
	if (ptr[0] == 'f' && !ptr[1] && type.find_first_of(".") != std::string::npos) // float case
		return 1;
	else if (!*ptr && type.find_first_of(".") != std::string::npos) // double case
		return 2;
	return 0;
}

int detectType(std::string &type, double *myDb)
{
	int lenBefore = type.length();
	if (imposy(type) == 0)
		return 0;
	if (lenBefore == 1 && !std::isdigit(type[0]))
		return 1;
	std::string str = type;
	size_t find = str.find_first_not_of("0123456789");
	size_t findAll = str.find_first_not_of("+-0123456789");
	size_t pos = str.find_last_of("+-");
	if (find == std::string::npos || (findAll == std::string::npos && pos == 0))
		return 2;
	if (check_dbft(type, myDb) == 1)
		return 3;
	if (check_dbft(type, myDb) == 2)
		return 4;
	if (check_nano(type))
		return 5;
	return 0;
}

void char_type(std::string type)
{
	std::cout << "char: " << type[0] << '\n';
	std::cout << "int: " << static_cast<int>(type[0]) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type[0]) << "f\n";
	std::cout << "double: " << static_cast<double>(type[0]) << "\n";
}

void int_type(std::string type)
{
	char* end_ptr;
	errno = 0;
	long val = std::strtol(type.c_str(), &end_ptr, 10);
	int typeInt = atoi(type.c_str());
	print_char(typeInt);
	if (val < INT_MIN || val > INT_MAX || errno == ERANGE)
	{
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	else
	{
		std::cout << "int: " << typeInt << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(typeInt) << "f\n";
		std::cout << "double: " << static_cast<double>(typeInt) << "\n";
	}
}
void floatDoubtype(double myDb)
{
	std::cout << std::fixed << std::setprecision(1);
	print_char(myDb);
	if (errno == ERANGE || myDb < INT_MIN || myDb > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(myDb) << "\n";
	std::cout << "float: " << static_cast<float>(myDb) << "f\n";
	std::cout << "double: " << myDb << "\n";
}

void ScalarConverter::convert(std::string type)
{
	double myDb = 0;
	int retType = detectType(type, &myDb);
	
	if (retType == 0)
	{
		allImposi();
		return ;
	}
	/******************CHAR_TYPE**************/
	if (retType == 1)
		char_type(type);
	/******************INT_TYPE**************/
	if (retType == 2)
		int_type(type);
	/******************FLOAT_TYPE && DOUBLE_TYPE**************/
	if (retType == 3 || retType == 4)
		floatDoubtype(myDb);
}

ScalarConverter::~ScalarConverter(){}