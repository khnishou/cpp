
#include "Intern.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

Intern::Intern() {}

Intern::Intern(Intern& other) {}

Intern::~Intern() { std::cout << ORANGE << "Intern destructor called\n" << DEFAULT; }

Intern& Intern::operator=(const Intern& other) {
	return (*this);
}

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& o, Intern const& obj) {
	o << "Intern" << std::endl;
	return (o);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    auto it = formMap.find(name);
    if (it != formMap.end()) {
        std::cout << "Intern creates " << name << std::endl;
        AForm* newForm = new AForm(name);
        newForm->setTarget(target);
        return newForm;
    } else {
        std::cout << RED <<"Error: Form '" << name << "' does not exist!" << DEFAULT << std::endl;
        return nullptr;
    }
}
