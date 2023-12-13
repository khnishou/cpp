
#include "Form.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

Form::Form(std::string name, bool sign, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	this->_signed = sign;
}

Form::Form() : _name("random"), _signGrade(150), _execGrade(150) { this->_signed = false; }

Form::~Form() { std::cout << ORANGE << this->getName() << " Form destructor called\n" << DEFAULT; }

Form& Form::operator=(const Form& other) {
	*this = other;
	return (*this);
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string Form::getName(void) const { return (this->_name); }

bool Form::getSigned(void) const { return (this->_signed); }

int Form::getSignGrade(void) const { return (this->_signGrade); }

int Form::getExecGrade(void) const { return (this->_execGrade); }

void Form::setSigned(bool sign) { this->_signed = sign; }

void Form::beSigned(Bureaucrat& bur) {
	if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		setSigned(true);
}

/******************************************************************************/
/*                           Error Message Function                           */
/******************************************************************************/

const char* Form::GradeTooHighException::what() const throw() { return "grade too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "grade too low"; }

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& o, Form const& obj) {
	o << "Form       : " << obj.getName() << std::endl;
	o << "Status     : " << obj.getSigned() << std::endl;
	o << "Sign grade : " << obj.getSignGrade() << std::endl;
	o << "Exec grade : " << obj.getExecGrade() << std::endl;
	return (o);
}