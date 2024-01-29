
#pragma once

#include <deque>
#include <string>
#include <cmath>

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

class RPN {
   private:
	std::deque<double> operand;
	
   public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN & operator=(const RPN &other);
	
	void chToD(char ch);

	void arithAdd(void);
	void arithSub(void);
	void arithMul(void);
	void arithDiv(void);

	void calculus(std::string arg);

	class syntaxError : public std::exception {
		virtual const char* what() const throw();
	};

	class mathError : public std::exception {
		virtual const char* what() const throw();
	};
};