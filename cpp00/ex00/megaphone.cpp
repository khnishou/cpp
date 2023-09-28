
#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	int i;
	int j;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				argv[i][j] = std::toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}