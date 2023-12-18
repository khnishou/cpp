
#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
    private:

    public:
	    Intern(Intern& other);
        Intern();
        ~Intern();
        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& name, const std::string& target);

        class InvalidName : public std::exception {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, Intern const& obj);
