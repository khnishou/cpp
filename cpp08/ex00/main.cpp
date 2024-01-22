#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        std::vector<int>::iterator it = easyfind(numbers, 3);
        std::cout << GREEN << "Found: " << DEFAULT << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
    return 0;
}
