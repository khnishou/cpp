#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


void	shrubberyCreationFormTest() {
	std::cout << YELLOW << "\n\n*************** ShrubberyCreationTest ***************" << DEFAULT << std::endl;
	AForm* form = NULL;
	try {
		Intern klawi;
		form = klawi.makeForm("ShrubberyCreationForm", "khnishou");
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ross.signForm(*form);
		harvey.executeForm(*form);
		ross.executeForm(*form);
		delete (form);
	} catch(const std::exception& e) {
		if (form)
			delete (form);
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void	RobotomyRequestFormTest() {
	std::cout << YELLOW
			<< "\n\n*************** RobotomyRequestTest ***************"
			<< DEFAULT << std::endl;
	AForm* form = NULL;
	try {
		Intern klawi;
		form = klawi.makeForm("RobotomyRequestForm", "khnishou");
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ross.signForm(*form);
		harvey.executeForm(*form);
		ross.executeForm(*form);
		delete (form);
	} catch(const std::exception& e) {
		if (form)
			delete (form);
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void	PresidentialPardonFormTest() {
	std::cout << YELLOW << "\n\n*************** PresidentialPardonTest ***************" << DEFAULT << std::endl;
	AForm* form = NULL;
	try{
		Intern klawi;
		form = klawi.makeForm("PresidentialPardonForm", "khnishou");
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ross.signForm(*form);
		harvey.executeForm(*form);
		ross.executeForm(*form);
		delete (form);
	} catch(const std::exception& e) {
		if (form)
			delete (form);
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

int	main()
{
	shrubberyCreationFormTest();
	RobotomyRequestFormTest();
	PresidentialPardonFormTest();

	return 0;
}