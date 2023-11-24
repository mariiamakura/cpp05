#include "../include/Intern.hpp"

Intern::Intern() {
    std::cout << "%% Intern created" <<std::endl;
}

Intern::Intern(const Intern &src) {
    *this = src;
    std::cout << "%% Intern COPY created" <<std::endl;
}

Intern &Intern::operator=(const Intern &src) {
    if (this != &src)
        this = src;
    std::cout << "%% Intern operator= called" <<std::endl;
    return (*this);
}

Intern::~Intern() {
    std::cout << "%% Intern deleted" << std::endl;
}

static Form *makeScrubbery(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

static Form *makeRobotomy(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

staticForm *makePresident(const std::string &target) {
    return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    AForm *(*all_foo[3])(const std::string &target) = {&makeScrubbery, &makeRobotomy, &makePresident};
    const std::string form_name[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0, i < 3; i++)
    {
        if (name == form_name[i])
        {
            std::cout << "Intern created " << name << std::endl;
            return (all_foo[i](target));
        }
    }
    std::cout << RED << "Intern can't create " << name << RESET << std::endl;
}