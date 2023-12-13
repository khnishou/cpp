
#include "Bureaucrat.hpp"

//****************************************************************************//
//                          Constructor & Destructor                          //
//****************************************************************************//

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat() : _name("random") { this->_grade = 150; }

Bureaucrat::~Bureaucrat() {
	std::cout << ORANGE << this->getName() << "Bureaucrat destructor called\n" << DEFAULT;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	this->setGrade(other.getGrade());
	return (*this);
}

//****************************************************************************//
//                              Accessor Methods                              //
//****************************************************************************//

std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::setGrade(int grade) { this->_grade = grade; }

void Bureaucrat::Decrement(void) {
	if ((this->getGrade() + 1) > 150)
		GradeTooLowException();
	else
		this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::Increment(void) {
	if ((this->getGrade() - 1) < 1)
		GradeTooHighException();
	else
		this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::signForm(AForm& other) {
	if (other.getSigned())
		std::cout << BLUE << this->getName() << " couldn't sign " << other.getName()
				  << " because it's already signed." << std::endl;
	else {
		std::cout << GREEN << this->getName() << " signed " << other.getName() << DEFAULT
				  << std::endl;
		try {
			other.beSigned(*this);
		} catch (const std::exception& e) {
			std::cerr << RED << other.getName() << " " << e.what() << DEFAULT << '\n';
		}
	}
}

//****************************************************************************//
//                           Error Message Function                           //
//****************************************************************************//

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }
const char* Bureaucrat::signNegative::what() const throw() { return "form not signed"; }
const char* Bureaucrat::reqGradeSignTooLow::what() const throw() { return "grade sign required too low"; }
const char* Bureaucrat::reqGradeExecTooLow::what() const throw() { return "grade exec required too low"; }

//****************************************************************************//
//                               Other Function                               //
//****************************************************************************//

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bur) {
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (this->getGrade() > form.getReqGradeSign())
		throw reqGradeSignTooLow();
	if (this->getGrade() > form.getReqGradeExec())
		throw reqGradeExecTooLow();
	if (!form.getSigned())
		throw signNegative();
	form.execute(*this);
}
