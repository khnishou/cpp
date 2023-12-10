
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat();
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        std::string getName(void) const;
        int         getGrade(void) const;

        void Increment(void);
        void Decrement(void);

        void signForm(Form& form);
};
std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj);

#endif
