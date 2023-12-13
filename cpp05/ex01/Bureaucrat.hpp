
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define DEFAULT "\033[1;39m"

#include <iostream>
#include <string>

#include "Form.hpp"
class Form;

class Bureaucrat {
   private:
	const std::string _name;
	int _grade;

   public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat();
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);

	class GradeTooHighException : public std::exception {
	   public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	   public:
		const char* what() const throw();
	};

	void setGrade(int grade);
	std::string getName(void) const;
	int getGrade(void) const;

	void Increment(void);
	void Decrement(void);

	void signForm(Form& form);
};
std::ostream& operator<<(std::ostream& o, Bureaucrat const& obj);

#endif
