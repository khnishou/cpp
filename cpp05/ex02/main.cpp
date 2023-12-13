#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	shrubberyCreationFormTest()
{
	std::cout << YELLOW
			<< "\t\t\tshrubberyCreationFormTest EXAMPLE"
			<< DEFAULT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		ShrubberyCreationForm	form("tree_1");
		ross.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED
				<< e.what()
				<< DEFAULT << std::endl;
	}
}

void	RobotomyRequestFormTest()
{
	std::cout << YELLOW
			<< "\t\t\tRobotomyRequestFormTest EXAMPLE"
			<< DEFAULT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		RobotomyRequestForm	form("AutomativeWork");
		ross.signForm(form);
		harvey.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED
				<< e.what()
				<< DEFAULT << std::endl;
	}
}

void	PresidentialPardonFormTest()
{
	std::cout << YELLOW
			<< "\t\t\tPresidentialPardonFormTest EXAMPLE"
			<< DEFAULT << std::endl;
	try
	{
		Bureaucrat	harvey("Harvey", 1);
		Bureaucrat	ross("Ross", 140);

		PresidentialPardonForm	form("Francesco");
		ross.signForm(form);
		harvey.signForm(form);
		form.execute(harvey);
		form.execute(ross);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED
				<< e.what()
				<< DEFAULT << std::endl;
	}
}

int	main()
{
	shrubberyCreationFormTest();
	RobotomyRequestFormTest();
	PresidentialPardonFormTest();

	return 0;
}