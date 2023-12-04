
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const char  *name;
        int         grade;
    public:
        Bureaucrat(char *name, int grade);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);
};

#endif
