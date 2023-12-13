
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string getTarget(void) const;

		virtual void execute(const Bureaucrat &executor) const;
		virtual int getReqGradeSign(void) const;
		virtual int getReqGradeExec(void) const;

		static const int reqGradeSign = 145;
		static const int reqGradeExec = 137;

};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& obj);

#endif
