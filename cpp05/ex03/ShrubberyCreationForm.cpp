
#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	: _target(other.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm() : _target("random") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << ORANGE << this->getTarget() << " ShrubberyCreationForm destructor called\n" << DEFAULT;
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
	std::ofstream file;
	file.open(this->getTarget() + "_shrubbery");
	if (file.is_open()) {
		file << "        *" << std::endl;
		file << "       /|\\" << std::endl;
		file << "      / | \\" << std::endl;
		file << "     /  |  \\" << std::endl;
		file << "    /___|___\\" << std::endl;
		file << "   //       \\\\" << std::endl;
		file << "  //         \\\\" << std::endl;
		file << " //___________\\\\" << std::endl;
		file << "       |||" << std::endl;
		file << "       |||" << std::endl;
	}
	std::cout << GRAY << "ASCII tree created." << DEFAULT << std::endl;	
}