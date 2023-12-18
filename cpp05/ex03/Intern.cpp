
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
    std::string const f_list[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int i = 0;

    while (i < 3 && f_list[i] != name)
        i++;
    AForm* form;
    switch (i)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            break ;
        case 1:
            form = new RobotomyRequestForm(target);
            break ;
        case 2:
            form = new ShrubberyCreationForm(target);
            break ;
        default:
            throw Intern::InvalidName();
    }
    std::cout << GRAY << "Intern created " << name << DEFAULT << std::endl;
    return (form);
}

const char* Intern::InvalidName::what() const throw() { return "Invalid name"; }
