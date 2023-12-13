
#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
	: _target(other.getTarget()) {}

PresidentialPardonForm::PresidentialPardonForm() : _target("random") {}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << ORANGE << this->getTarget() << " destructor called\n" << DEFAULT;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	return (*this);
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string PresidentialPardonForm::getTarget(void) const { return (this->_target); }

int PresidentialPardonForm::getReqGradeSign(void) const { return (this->reqGradeSign); }

int PresidentialPardonForm::getReqGradeExec(void) const { return (this->reqGradeExec); }

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& obj) {
	o << "PresidentialPardonForm target " << obj.getTarget() << ".";
	return o;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() <= getExecGrade() && getSigned()) {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		throw GradeTooLowException();
	}
}
