#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();

        AForm *makeForm(const std::string &name, const std::string &target);
};

