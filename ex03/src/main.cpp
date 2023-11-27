#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    Intern student;
    Bureaucrat first("first", 20);

    AForm *shrubbery = student.makeForm("ShrubberyCreationForm", "shrubbery");
    std::cout << *shrubbery;
    shrubbery->beSigned(first);
    shrubbery->execute(first);
    std::cout << *shrubbery << std::endl;

    AForm *robotomy = student.makeForm("RobotomyRequestForm", "Robotomy");
    std::cout << *robotomy;

    AForm *presidential = student.makeForm("PresidentialPardonForm", "Presidential");
    std::cout << *presidential;

    student.makeForm("PresidetialPardonForm", "Presidetial");

    delete (shrubbery);
    delete (robotomy);
    delete (presidential);

}