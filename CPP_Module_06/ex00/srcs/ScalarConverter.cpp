#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter()
{
	//std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& param)
{
	//std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	(void)param;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& param)
{
	//std::cout << "ScalarConverter: Copy assignment operator called" << std::endl;
	if (this != &param)
		(void)param;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter: Default destructor called" << std::endl;
}

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	isOnce(std::string str, std::string c)
{
	return (str.find_first_of(c) == str.find_last_of(c));
}

static bool	isAtLeastOne(std::string str, std::string c)
{
	return (str.find_first_of(c) != std::string::npos);
}

static bool	isLast(std::string str, std::string c)
{
	if (str.find_first_of(c) == std::string::npos || str.find_last_of(c) == str.size() - 1)
		return (true);
	return (false);
}

static	bool isFirst(std::string str, std::string c)
{
	if (str.find_first_of(c) == std::string::npos || str.find_first_of(c) == 0)
		return (true);
	return (false);
}

static bool checkDot(std::string str)
{
	return (!isOnce(str, ".") || (isAtLeastOne(str, ".") && (isFirst(str, ".") || isLast(str, "."))));
}

static bool checkF(std::string str)
{
	return (!isOnce(str, "f") || !isLast(str, "f"));
}

static bool checkSigns(std::string str)
{
	return (!isOnce(str, "-+") || !isFirst(str, "-+"));
}

static	bool	intOverflow(std::string str)
{
	if (atol(str.c_str()) > 2147483647 || atol(str.c_str()) < -2147483648)
		return (true);
	if (((str.at(0) != '-') && (str.size() > 10)) || (str.size() > 11 && str.at(0) == '-'))
		return (true);
	return (false);
}

static	bool isPseudoLiterals(std::string str)
{
	return (str == "nan" || str == "nanf" || str == "-inf" || str == "inf" || str == "+inf" || str == "-inff" || str == "inff" || str == "+inff");
}

void	ScalarConverter::convert(std::string str)
{
	if (str.empty())
	{
		std::cout << "Invalid input!" << std::endl;
		return ;
	}
	if (str.size() == 1 && !isdigit(str.at(0)))
		convertChar(static_cast<char>(str.at(0)));
	else if (isPseudoLiterals(str))
		convertPseudoLiterals(str);
	else if	(checkSigns(str) || checkF(str) || checkDot(str))
		std::cout << "Invalid input!" << std::endl;
	else if (str.find_first_not_of("0123456789-+") == std::string::npos)
		convertInt(atoi(str.c_str()), str);
    else if (str.find_first_not_of("0123456789-+.") == std::string::npos)
        convertDouble(static_cast<double>(atof(str.c_str())), str);
    else if (str.find_first_not_of("0123456789-+.f") == std::string::npos)
        convertFloat(atof(str.c_str()), str);
    else {
		std::cout << "Invalid input!" << std::endl;
    }
}

void	ScalarConverter::convertChar(char stringToChar)
{
	if (stringToChar >= 32 && stringToChar <= 126)
		std::cout << "char: '" << stringToChar << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(stringToChar) << std::endl;
	std::cout << "float: " << static_cast<float>(stringToChar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(stringToChar) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(int stringToInt, std::string str)
{
	if (intOverflow(str))
	{
		printImpossible();
		return ;
	}
	if (stringToInt >= 32 && stringToInt <= 126)
		std::cout << "char: '" << static_cast<char>(stringToInt) << "'" << std::endl;
	else if (stringToInt >= 0 && stringToInt <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << stringToInt << std::endl;
	std::cout << "float: " << static_cast<float>(stringToInt);
	if (stringToInt <= 999999 && stringToInt >= -999999)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << static_cast<double>(stringToInt);
	if (stringToInt <= 999999 && stringToInt >= -999999)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convertFloat(float stringToFloat, std::string str)
{
	if (stringToFloat >= 32 && stringToFloat < 127)
		std::cout << "char: '" << static_cast<char>(stringToFloat) << "'" << std::endl;
	else if (stringToFloat >= 0 && stringToFloat < 128)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (intOverflow(str))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(stringToFloat) << std::endl;
	std::cout << "float: " << stringToFloat;
	if (stringToFloat <= 999999 && stringToFloat >= -999999)
	{
		if (roundf(stringToFloat) == stringToFloat)
			std::cout << ".0f";
		else
			std::cout << "f";
	}
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << static_cast<double>(stringToFloat);
	if (stringToFloat <= 999999 && stringToFloat >= -999999 && roundf(stringToFloat) == stringToFloat)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convertDouble(double stringToDouble, std::string str)
{
	if (stringToDouble >= 32 && stringToDouble < 127)
		std::cout << "char: '" << static_cast<char>(stringToDouble) << "'" << std::endl;
	else if (stringToDouble >= 0 && stringToDouble < 128)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (intOverflow(str))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(stringToDouble) << std::endl;
	std::cout << "float: " << static_cast<float>(stringToDouble);
	if (stringToDouble <= 999999 && stringToDouble >= -999999)
	{
		if (roundf(stringToDouble) == stringToDouble)
			std::cout << ".0f";
		else
			std::cout << "f";
	}
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << stringToDouble;
	if (stringToDouble <= 999999 && stringToDouble >= -999999 && roundf(stringToDouble) == stringToDouble)
			std::cout << ".0";
	std::cout << std::endl;
}

static	void print_not_a_number()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static	void print_positive_infinity()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

static	void print_negative_infinity()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	ScalarConverter::convertPseudoLiterals(std::string str)
{
	if (str == "nan" || str == "nanf")
		print_not_a_number();
	else if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
		print_positive_infinity();
	else
		print_negative_infinity();
}
