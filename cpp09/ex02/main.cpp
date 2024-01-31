#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;


    if (!(argc <= 2))
    {
		try
		{
			PmergeMe cont(argc, argv);

			cont.sortVec();
			cont.sortDeq();
		} catch (const std::string str) {
			std::cout << RED << "Error: " << DEFAULT << str <<  std::endl;
		}
    }
    else
		std::cerr << RED << "Error: " << DEFAULT << "Incorrect number of arguments provided" << std::endl;
}
