#include "../include/Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : 
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {

		checkGrade(gradeToSign);
		checkGrade(gradeToExec);
		this->_isSigned = false;
		std::cout << "### From " << getName() << " created" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec) {
	this->_isSigned = src._isSigned;

	std::cout << "### From COPY " << getName() << " created" << std::endl;
}

Form& Form::operator=(const Form &src) {
	if (this != &src)
		this->_isSigned = src._isSigned;
	std::cout << "### From =OPERATOR called" << std::endl;
	return (*this);
}

Form::~Form() {
	std::cout << "### From " << getName() << " destroyed" << std::endl;
}

const std::string &Form::getName() const {
	return (this->_name);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const {
	return (this->_gradeToExec);
}

bool Form::isSigned() const {
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_isSigned == true)
		throw Form::AlreadySigned();
	else if (this->getGradeToSign() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("### Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("### Form grade to low!");
}

const char *Form::AlreadySigned::what() const throw() {
	return ("### Form already signed");
}

void Form::checkGrade(const int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form &src) {
	o << "(ostram overload) Form " << src.getName() << " with sign grade " << 
		src.getGradeToSign() << " and exec grade " << src.getGradeToExec() << 
		" is signed = " << src.isSigned() << std::endl;
	return (o);
}



// void Form::increaseGrade() { //to test const int
// 	this->_gradeToExec += 1;
// }