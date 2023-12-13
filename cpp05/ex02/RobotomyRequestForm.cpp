
#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : _target(other.getTarget()) {}

RobotomyRequestForm::RobotomyRequestForm() : _target("random") {}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << ORANGE << this->getTarget() << " destructor called\n" << DEFAULT;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	return (*this);
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string RobotomyRequestForm::getTarget(void) const { return (this->_target); }

int RobotomyRequestForm::getReqGradeSign(void) const { return (this->reqGradeSign); }

int RobotomyRequestForm::getReqGradeExec(void) const { return (this->reqGradeExec); }

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& obj) {
	o << "RobotomyRequestForm target " << obj.getTarget() << ".";
	return o;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() <= getExecGrade() && getSigned()) {
		srand(time(NULL));
		int success = rand() % 2;
		if (success) {
			std::cout << "Drilling noises... ";
			std::cout << _target << " has been robotomized successfully!" << std::endl;
		} else {
			std::cout << "Drilling noises... Robotomy failed for " << _target << std::endl;
		}
	} else {
		throw GradeTooLowException();
	}
}
