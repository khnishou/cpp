
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& other);
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		std::string getTarget(void) const;

		virtual void execute(const Bureaucrat &executor) const;
		virtual int getReqGradeSign(void) const;
		virtual int getReqGradeExec(void) const;

		static const int reqGradeSign = 25;
		static const int reqGradeExec = 5;

};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& obj);

#endif
