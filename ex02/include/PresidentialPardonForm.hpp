#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    virtual ~PresidentialPardonForm();

    const std::string &getTarget() const;
    virtual void createForm() const;
};