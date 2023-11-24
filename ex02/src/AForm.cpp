#include "../include/AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : 
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

		checkGrade(gradeToSign);
		checkGrade(gradeToExec);
		this->_isSigned = false;
		std::cout << "### From " << getName() << " created" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec) {
	this->_isSigned = src._isSigned;

	std::cout << "### From COPY " << getName() << " created" << std::endl;
}

AForm& AForm::operator=(const AForm &src) {
	if (this != &src)
		this->_isSigned = src._isSigned;
	std::cout << "### From =OPERATOR called" << std::endl;
	return (*this);
}

AForm::~AForm() {
	std::cout << "### From " << getName() << " destroyed" << std::endl;
}

const std::string &AForm::getName() const {
	return (this->_name);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const {
	return (this->_gradeToExec);
}

bool AForm::isSigned() const {
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_isSigned == true)
		throw AForm::AlreadySigned();
	else if (this->getGradeToSign() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("### AForm grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("### AForm grade to low!");
}

const char *AForm::AlreadySigned::what() const throw() {
	return ("### AForm already signed");
}

void AForm::checkGrade(const int grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm &src) {
	o << "(ostram overload) AForm " << src.getName() << " with sign grade " << 
		src.getGradeToSign() << " and exec grade " << src.getGradeToExec() << 
		" is signed = " << src.isSigned() << std::endl;
	return (o);
}



// void AForm::increaseGrade() { //to test const int
// 	this->_gradeToExec += 1;
// }