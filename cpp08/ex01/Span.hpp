#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <vector>

class Span {
   private:
	std::vector<int> vec;
	unsigned int size;

   public:
	Span(unsigned int N);
	~Span();
	Span(Span const& other);

	Span& operator=(const Span& other);

	class OutOfElements : public std::exception {
	   public:
		const char* what() const throw();
	};
	class NotEnoughElements : public std::exception {
	   public:
		const char* what() const throw();
	};

	void addNumber(int nbr);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};