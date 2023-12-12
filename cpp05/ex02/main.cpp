
#include "Bureaucrat.hpp"

void	wrong_grade()
{
	std::cout << YELLOW << std::endl <<  "*************** wrong grade ***************" << DEFAULT << std::endl;
	try
	{	
		Bureaucrat	ross("Ross", 50);
		Bureaucrat	harvey("Harvey", 1);

		AForm	top1("A1", false, 5, 5);
		AForm	low1("C5", false, 25, 25);
		AForm	mid1("B2", false, 25, 25);

		harvey.signAForm(top1);
		harvey.signAForm(top1);
		ross.signAForm(low1);
		ross.signAForm(mid1);
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
		AForm	tooLow("Wrong", false, 151, 151);
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