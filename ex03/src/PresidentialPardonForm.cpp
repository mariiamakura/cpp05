#include "../include/PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <time.h>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
        AForm("President_pardon", 25, 5), _target(target) {

    std::cout << "&& Presidential constractor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
        AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), _target(src.getTarget()) {
    std::cout << "&& Presidential COPY constractor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src)
        AForm::operator=(src);
    std::cout << "&& Presidential COPY operator= called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "&& Presidential deconstructor called" << std::endl;
}

void PresidentialPardonForm::createForm() const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return (this->_target);
}