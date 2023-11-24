#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"



void testPresident() {
    PresidentialPardonForm sh_1("president");
    std::cout << sh_1;

    //can't exec, grade too low
    try {
        {
            Bureaucrat b_one("-1-", 26);
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
            Bureaucrat b_one("-1-", 5);
            sh_1.execute(b_one);
        }
    } catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    //test b function execForm
    try {
        Bureaucrat b_one("-1-", 6);
        b_one.executeForm(sh_1);
    } catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    Bureaucrat b_one("-1-", 5);
    sh_1.beSigned(b_one);
    sh_1.execute(b_one);
}

void  testRobotomy() {
    RobotomyRequestForm sh_1("robot");
    std::cout << sh_1;

    //can't exec, grade too low
    try {
        {
            Bureaucrat b_one("-1-", 46);
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

    //test b function execForm
    try {
        Bureaucrat b_one("-1-", 20);
        b_one.executeForm(sh_1);
    } catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }



    Bureaucrat b_one("-1-", 45);
    sh_1.beSigned(b_one);
    sh_1.execute(b_one);
}

void testShrubbery() {
	ShrubberyCreationForm sh_1("Shrubbery");
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

    //test b function execForm
    try {
            Bureaucrat b_one("-1-", 20);
            b_one.executeForm(sh_1);
    } catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }



	Bureaucrat b_one("-1-", 130);
	sh_1.beSigned(b_one);
	sh_1.execute(b_one);
}

int main()
{
	//abstact class check
	//AForm one("-111-", 1, 1);

	//testShrubbery();
    //testRobotomy();
    testPresident();

}