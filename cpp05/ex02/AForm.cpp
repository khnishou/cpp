
#include "AForm.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

AForm::AForm(std::string name, bool sign, int signGrade, int execGrade):_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	this->_signed = sign;
}

AForm::AForm():_name("random"), _signGrade(150), _execGrade(150)
{
	this->_signed = false;
}

AForm::~AForm()
{
	std::cout << ORANGE << this->getName() << " AForm destructor called\n" << DEFAULT;
}

AForm& AForm::operator=(const AForm& other)
{
	*this = other;
	return (*this);
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

void execute(Bureaucrat const & executor) const
{

}


/******************************************************************************/
/*                           Error Message Function                           */
/******************************************************************************/

const char * AForm::GradeTooHighException::what() const throw() 
{
    return "grade too high";
}
const char * AForm::GradeTooLowException::what() const throw() 
{
    return "grade too low";
}

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream & operator<<(std::ostream & o, AForm const & obj)
{
	o << "AForm       : " << obj.getName() << std::endl;
	o << "Status     : " << obj.getSigned() << std::endl;
	o << "Sign grade : " << obj.getSignGrade() << std::endl;
	o << "Exec grade : " << obj.getExecGrade() << std::endl;
	return (o);
}