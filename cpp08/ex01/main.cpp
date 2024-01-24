#include "Span.hpp"
#include <iostream>

void testSpan1() {
    try
    {
        Span span(5);

        std::cout << BLUE << "Test 1: Adding numbers and calculating spans" << DEFAULT << std::endl;

        span.addNumber(5);
        span.addNumber(10);
        span.addNumber(3);
        span.addNumber(8);
        span.addNumber(15);

        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();

        std::cout << "Shortest Span: " << GREEN << shortest << DEFAULT << std::endl;
        std::cout << "Longest Span: " << GREEN << longest << DEFAULT << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSpan2() {
    try
    {
        Span span(2);

        std::cout << BLUE << "Test 2: Trying to add more than allowed numbers" << DEFAULT << std::endl;

        span.addNumber(5);
        span.addNumber(10);
        span.addNumber(3);

        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();

        std::cout << "Shortest Span: " << GREEN << shortest << DEFAULT << std::endl;
        std::cout << "Longest Span: " << GREEN << longest << DEFAULT << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

void testSpan3() {
    try {
        Span span(10000);

        std::cout << BLUE << "Test Case 3: Adding 10,000 numbers and calculating spans" << DEFAULT << std::endl;

        for (int i = 1; i <= 10000; ++i) {
            span.addNumber(i);
        }

        unsigned int shortest = span.shortestSpan();
        unsigned int longest = span.longestSpan();

        std::cout << "Shortest Span: " << GREEN << shortest << DEFAULT << std::endl;
        std::cout << "Longest Span: " << GREEN << longest << DEFAULT << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
}

int main() {
    testSpan1();
    testSpan2();
    testSpan3();
    return 0;
}
