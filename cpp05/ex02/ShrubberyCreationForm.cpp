
#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):_target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other):_target(other.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm():_target("random") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->_target = other.getTarget();
}

/******************************************************************************/
/*                              Accessor Methods                              */
/******************************************************************************/

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & obj)
{
	o << "ShrubberyCreationForm : " << obj.getTarget() << std::endl;
	return (o);
}