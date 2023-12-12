
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);

		std::string getTarget(void) const;



		static const int reqSignGrade = 145;
		static const int reqExecGrade = 137;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & obj);

#endif