#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	shrubberyCreationFormTest() {
	std::cout << YELLOW << "\n\n*************** ShrubberyCreationTest ***************" << DEFAULT << std::endl;
	try {
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ShrubberyCreationForm	form("Khnisou");
		ross.signForm(form);
		harvey.executeForm(form);
		ross.executeForm(form);
	} catch(const std::exception& e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void	RobotomyRequestFormTest() {
	std::cout << YELLOW
			<< "\n\n*************** RobotomyRequestTest ***************"
			<< DEFAULT << std::endl;
	try {
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		RobotomyRequestForm	form("Khnishou");
		ross.signForm(form);
		harvey.executeForm(form);
		ross.executeForm(form);
	} catch(const std::exception& e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void	PresidentialPardonFormTest() {
	std::cout << YELLOW << "\n\n*************** PresidentialPardonTest ***************" << DEFAULT << std::endl;
	try{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		PresidentialPardonForm	form("Khnishou");
		ross.signForm(form);
		harvey.executeForm(form);
		ross.executeForm(form);
	} catch(const std::exception& e) {
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