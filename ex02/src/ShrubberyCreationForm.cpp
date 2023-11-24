#include "../include/ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137), _target(target) {
			std::cout << "** Shrubbery form created" << std::endl;
		}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()),
		_target(src.getTarget()) {
			std::cout << "** Shrubbery COPY form created" << std::endl;
		}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		AForm::operator=(src);
	};
	std::cout << "** Shrubbery OPERATOR= form created" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "** Shrubbery destructor called" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &src) {
	o << "Shrubbery form with target " << src.getTarget() << " sign grade " 
	<< src.getGradeToSign() << " and exec grade " << src.getGradeToExec() << std::endl;
	return (o);
}

void ShrubberyCreationForm::createForm() const {
	// Create an ofstream (output file stream) object
	std::ofstream file; 
	file.open((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		std::cerr << "Error opening file" << std::endl;
	file << 
	"   *   \n"
	"  ***  \n"
	" ***** \n"
	"   *   \n"
	"   *   ";
	file.close();
}


