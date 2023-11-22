#pragma once

#include <iostream>

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

		void incrementGrade();
		void decrementGrade();

		//exceptions
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src);
