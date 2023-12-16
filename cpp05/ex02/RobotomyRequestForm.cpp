
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : _target(other.getTarget()) {}

RobotomyRequestForm::RobotomyRequestForm() : _target("random") {}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << ORANGE << this->getTarget() << " RobotomyRequestForm destructor called\n" << DEFAULT;
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
	std::cout << GRAY << "*drilling noises*" << DEFAULT << std::endl;
	if (rand() % 2) {
		std::cout << GRAY << this->getTarget() << " has been robotomized successfull" << DEFAULT << std::endl;
	}
	else {
		std::cout << GRAY << "the robotomy failed." << DEFAULT << std::endl;
	}
}
