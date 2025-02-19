#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>


class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		static void	convertChar(char stringToChar);
		static void	convertInt(int stringToInt, std::string str);
		static void	convertFloat(float stringToFloat, std::string str);
		static void	convertDouble(double stringToDouble, std::string str);
		static void convertPseudoLiterals(std::string str);
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
};

#endif