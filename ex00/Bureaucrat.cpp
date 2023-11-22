#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	this->setGrade(grade);
	std::cout << "Bureaucrat " << getName() << " with grade " << getGrade() << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()) {
	*this = src;
	std::cout << "Bureaucrat COPY" << getName() << " with grade " << getGrade() << " created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
	{
			//this->_name = src.getName();
			this->_grade = src.getGrade();
	}
	std::cout << "Bureaucrat " << getName() << " with grade " << getGrade() << "  COPY_OPERATOR called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << getName() << " with grade " << getGrade() << "  destroyed" << std::endl;
}


//member functions

int Bureaucrat::getGrade() const {
	//if >150
	//or  < 0
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	this->setGrade(this->_grade - 1);
	std::cout << this->_name << " incremented by 1 and now is " << this->_grade <<std::endl;
}

void Bureaucrat::decrementGrade() {
	this->setGrade(this->_grade + 1);
	std::cout << this->_name << " decremented by 1 and now is " << this->_grade <<std::endl;
} 

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src) {
	o << "(ostream overload) Beraucrat " << src.getName() << " with grade " << src.getGrade() << std::endl;
	return (o);
}