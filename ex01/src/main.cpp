#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	//grade too high
	try {
		Form one("-111-", 0, 1);
	}	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//grade too low
	try {
		Form one("-111-", 151, 1);
	}	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Form one("-111-", 1, 1);
	Form oneCopy(one);
	Form two("--222--", 2, 2);
	two = one;

	//can't sign since b grade is lower than form
	try {
		Bureaucrat fail("fail", 120);
		one.beSigned(fail);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//sign the 1 form
	Bureaucrat b_one("b_one", 1);
	one.beSigned(b_one);

	//stream overload
	std::cout << one;

	//form already signed
	try {
		one.beSigned(b_one);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//b sign the form by b class
	b_one.signForm(two);

	//try to sign one more time ERROR within b class
	b_one.signForm(two);

	//stream overload
	std::cout << one;
	std::cout << two;

}