
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Form
{
    private:
		const std::string 	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

    public:

		Form(std::string name, bool sign, int signGrade, int execGrade);
        Form();
        ~Form();

        Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
std::ostream & operator<<(std::ostream & o, Form const & obj);

#endif