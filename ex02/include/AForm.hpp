#pragma once 

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"

class Bureaucrat;

class AForm {
	protected:
		const std::string _name;
		bool _isSigned; //by default FALSE
		const int _gradeToSign;
		const int _gradeToExec;
	
	public:

		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);

		virtual ~AForm();

		const std::string &getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		//void increaseGrade(); to test const int 
		void beSigned(const Bureaucrat &bureaucrat); 
		void checkGrade(const int grade);

		//pure virtual for abstract class
		virtual void createForm() const = 0;
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class AlreadySigned: public std::exception {
			public:
				virtual const char *what() const throw();
		}; 

		class FormNotSigned: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm &src);