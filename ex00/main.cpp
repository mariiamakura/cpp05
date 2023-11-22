#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat one("*first*", 150);
	Bureaucrat three("//three//", 1);
	try {
		three.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Operation on " << one.getName() << " failed: " <<
		e.what() << std::endl;
	}

	try {
		one.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Operation on " << one.getName() << " failed: " <<
		e.what() << std::endl;
	}

	three.decrementGrade();
	one.incrementGrade();

	try {
		three.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Operation on " << one.getName() << " failed: " <<
		e.what() << std::endl;
	}

	std::cout << one; //ostream overload


	//Bureaucrat two(one); to test copy
	//three = one; to test copy
}