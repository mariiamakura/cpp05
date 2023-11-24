#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void testShrubbery() {
	ShrubberyCreationForm sh_1("home");
	std::cout << sh_1;

	//can't exec, grade too low
	try {
		{
			Bureaucrat b_one("-1-", 150);
			sh_1.execute(b_one);
		}
	} catch (std::exception &e)
	{
		std::cout << 
		RED << e.what() << RESET << std::endl;
	}

	//can't exec since it's not signed
	try {
		{
			Bureaucrat b_one("-1-", 20);
			sh_1.execute(b_one);
		}
	} catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Bureaucrat b_one("-1-", 20);
	sh_1.beSigned(b_one);
	sh_1.execute(b_one);
}

int main()
{
	//abstact class check
	//AForm one("-111-", 1, 1);

	testShrubbery();

}