
#include "Bureaucrat.hpp"

void	wrong_grade()
{
	std::cout << YELLOW << std::endl <<  "*************** wrong grade ***************" << DEFAULT << std::endl;
	try
	{	
		Bureaucrat	ross("Ross", 50);
		Bureaucrat	harvey("Harvey", 1);

		Form	top1("A1", false, 5, 5);
		Form	low1("C5", false, 25, 25);
		Form	mid1("B2", false, 25, 25);

		harvey.signForm(top1);
		harvey.signForm(top1);
		ross.signForm(low1);
		ross.signForm(mid1);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void	wrong_initialization()
{
	std::cout << YELLOW << std::endl << "*************** wrong init ***************" << DEFAULT << std::endl;
	try
	{
		Form	tooLow("Wrong", false, 151, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

int	main()
{
	wrong_grade();
	wrong_initialization();

	return 0;
}