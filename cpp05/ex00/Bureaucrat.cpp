
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}
Bureaucrat::Bureaucrat():name("random")
{
	this->grade = 150;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->setGrade(other.getGrade());
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

void Bureaucrat::Decrement(void)
{
	if ((this->getGrade() + 1) > 150)
		throw GradeTooLowException();
	else
		setGrade(this->getGrade() + 1);
}

void Bureaucrat::Increment(void)
{
	if ((this->getGrade() - 1) < 1)
		throw GradeTooHighException();
	else
		setGrade(this->getGrade() - 1);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "grade too low";
}