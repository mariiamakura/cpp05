#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {

	private:
		const std::string _name;
		int _grade;

	public:
		//constractor
		Bureaucrat(const std::string name, int grade);
		//copy
		Bureaucrat(const Bureaucrat &src);
		//copy operator
		Bureaucrat &operator=(const Bureaucrat &src);
		//destructor
		~Bureaucrat();

		void setGrade(int grade);
		const std::string getName() const;
		int getGrade() const;

		//ADDED for EX01
		void signForm(Form &form) const;

		void incrementGrade();
		void decrementGrade();

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src);
