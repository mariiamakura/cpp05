#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string.h>

class Bureaucrat;

class ShrubberyCreationForm: public AForm {
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();

		const std::string getTarget() const;
		virtual void createForm() const;
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &src);