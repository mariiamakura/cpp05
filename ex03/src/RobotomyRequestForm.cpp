#include "../include/RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
        AForm("robotomy", 72, 45), _target(target) {

    std::cout << "// Robotomy constractor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
        AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), _target(src.getTarget()) {
    std::cout << "// Robotomy COPY constractor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src)
        AForm::operator=(src);
    std::cout << "// Robotomy COPY operator= called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "// Robotomy deconstructor called" << std::endl;
}

void RobotomyRequestForm::createForm() const {
       std::cout << "// Makes some drilling noises //" << std::endl;
       srand(time(NULL));

       if (rand() % 2 == 0)
           std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
       else
           std::cout << this->getTarget() << " robotomy failed" << std::endl;

}

const std::string &RobotomyRequestForm::getTarget() const {
    return (this->_target);
}