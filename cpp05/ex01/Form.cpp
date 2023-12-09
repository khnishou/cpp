
#include "Form.hpp"

Form::Form(std::string name, bool sign, int signGrade, int execGrade):_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	
}
Form::Form():_name("random")
{
	
}
Form::~Form()
{
	std::cout << "Bureaucrat destructor called\n";
}