
#include "ShrubberyCreationForm.hpp"

#include <fstream>

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	: _target(other.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm() : _target("random") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << ORANGE << this->getTarget() << " destructor called\n" << DEFAULT;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	return (*this);
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string ShrubberyCreationForm::getTarget(void) const { return (this->_target); }

int ShrubberyCreationForm::getReqGradeSign(void) const { return (this->reqGradeSign); }

int ShrubberyCreationForm::getReqGradeExec(void) const { return (this->reqGradeExec); }

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& obj) {
	o << "ShrubberyCreationForm target " << obj.getTarget() << ".";
	return o;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() <= getExecGrade() && getSigned()) {
		std::ofstream file((_target + "_shrubbery").c_str());
		if (file.is_open()) {
			file << "ASCII trees";
			file.close();
		} else {
			throw std::runtime_error("Unable to create file");
		}
		std::cout << _target << " shrubbery created successfully!" << std::endl;
	} else {
		throw GradeTooLowException();
	}
}
