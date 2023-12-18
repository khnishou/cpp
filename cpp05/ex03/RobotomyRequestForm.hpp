
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string getTarget(void) const;

		virtual void execute(const Bureaucrat &executor) const;
		virtual int getReqGradeSign(void) const;
		virtual int getReqGradeExec(void) const;

		static const int reqGradeSign = 72;
		static const int reqGradeExec = 45;
};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& obj);

#endif
