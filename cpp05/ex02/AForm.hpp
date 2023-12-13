
#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
		const std::string 	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

    public:

		AForm(std::string name, bool sign, int signGrade, int execGrade);
        AForm();
        ~AForm();
        AForm& operator=(const AForm& other);

		std::string getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void beSigned(Bureaucrat& bur);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class SignedIsNegative : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream & operator<<(std::ostream & o, AForm const & obj);

#endif