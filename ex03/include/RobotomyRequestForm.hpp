#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        virtual ~RobotomyRequestForm();

        const std::string &getTarget() const;
        virtual void createForm() const;
};