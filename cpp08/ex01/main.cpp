#include "Span.hpp"
#include <iostream>

void testSpan() {
    try
    {
        Span span(5);

        std::cout << BLUE << "Test Case 1: Adding numbers and calculating spans" << DEFAULT << std::endl;

        span.addNumber(5);
        span.addNumber(10);
        span.addNumber(3);
        span.addNumber(8);
        span.addNumber(15);

        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();

        std::cout << "Shortest Span: " << GREEN << shortest << DEFAULT << std::endl;
        std::cout << "Longest Span: " << GREEN << longest << DEFAULT << std::endl;

        std::cout << BLUE << "Test Case 2: Trying to add more than allowed numbers" << DEFAULT << std::endl;

        span.addNumber(1);
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    testSpan();
    return 0;
}
