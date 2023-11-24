#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

int main()
{
	//grade too high
	try {
		AForm one("-111-", 0, 1);
	}	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//grade too low
	try {
		AForm one("-111-", 151, 1);
	}	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	AForm one("-111-", 1, 1);
	AForm oneCopy(one);
	AForm two("--222--", 2, 2);
	two = one;

	//can't sign since b grade is lower than AForm
	try {
		Bureaucrat fail("fail", 120);
		one.beSigned(fail);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//sign the 1 AForm
	Bureaucrat b_one("b_one", 1);
	one.beSigned(b_one);

	//stream overload
	std::cout << one;

	//AForm already signed
	try {
		one.beSigned(b_one);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	//b sign the AForm by b class
	b_one.signAForm(two);

	//try to sign one more time ERROR within b class
	b_one.signAForm(two);

	//stream overload
	std::cout << one;
	std::cout << two;

}