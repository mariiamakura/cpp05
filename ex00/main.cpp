#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat one("*first*", 150);
	Bureaucrat three("//three//", 1);
	one.decrementGrade();
	three.incrementGrade();

	std::cout << one; //ostream overload


	//Bureaucrat two(one); to test copy
	//three = one; to test copy
}