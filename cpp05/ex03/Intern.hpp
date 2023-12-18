
#pragma once

#include "AForm.hpp"
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
};

std::ostream& operator<<(std::ostream& o, Intern const& obj);
