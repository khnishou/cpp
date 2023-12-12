
#include "Bureaucrat.hpp"

//****************************************************************************//
//                          Constructor & Destructor                          //
//****************************************************************************//

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat():_name("random")
{
	this->_grade = 150;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << ORANGE << this->getName() << "Bureaucrat destructor called\n" << DEFAULT;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	*this = other;
	return (*this);
}

//****************************************************************************//
//                              Accessor Methods                              //
//****************************************************************************//

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::Decrement(void)
{
	if ((this->_grade + 1) > 150)
		GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::Increment(void)
{
	if ((this->_grade - 1) < 1)
		GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
		std::cout << BLUE << this->getName() << " couldn't sign "
			<< form.getName() << " because it's already signed." << std::endl;
	else
	{
		std::cout << GREEN << this->getName() << " signed " << form.getName()
			<< DEFAULT << std::endl;
		try
		{
			form.beSigned(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << form.getName() << " "
				<< e.what() << DEFAULT << '\n';
		}
		
	}
}

//****************************************************************************//
//                           Error Message Function                           //
//****************************************************************************//

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "grade too high";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

//****************************************************************************//
//                               Other Function                               //
//****************************************************************************//

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
