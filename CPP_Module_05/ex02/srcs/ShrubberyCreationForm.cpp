#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("unknown_shrubbery")
{
	//std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery")
{
	//std::cout << "ShrubberyCreationForm: Parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& param): AForm(param)
{
	//std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& param)
{
	//std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		AForm::operator=(param);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm: Default destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream tree_file(_target.c_str());
	if (!tree_file.is_open())
		throw AForm::FileNotOpenException();
	tree_file << "                          +							" << std::endl;
	tree_file << "                          #							" << std::endl;
	tree_file << "                         ###							" << std::endl;
	tree_file << "                 \"#:. .:##\"##:. .:#\"				" << std::endl;
	tree_file << "                 . \"####\"###\"####\"				" << std::endl;
	tree_file << "             \"#:.    .:#\"###\"#:.    .:#\"			" << std::endl;
	tree_file << "                \"#########\"#########\"				" << std::endl;
	tree_file << "             \"#:.  \"####\"###\"####\"  .:#\"		" << std::endl;
	tree_file << "              \"#######\"\"##\"##\"\"#######\"		" << std::endl;
	tree_file << "                .\"##\"#####\"#####\"##\"         	" << std::endl;
	tree_file << "        \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"	" << std::endl;
	tree_file << "            \"#######\"##\"#####\"##\"#######\"		" << std::endl;
	tree_file << "               \"#####\"\"#######\"\"#####\"			" << std::endl;
	tree_file << "                  \"      000      \"					" << std::endl;
	tree_file << "                         000							" << std::endl;
	tree_file << "                        O000O							" << std::endl;
	tree_file.close();
}
