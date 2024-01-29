
#include "RPN.hpp"
#include <iostream>

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

RPN::RPN()
{
}

RPN::~RPN()
{
    
}

RPN::RPN(const RPN& other)
{
    
}

/******************************************************************************/
/*                               OPERATOR OVERLOAD                            */
/******************************************************************************/

RPN & RPN::operator=(const RPN &other)
{ 
	this->operand = other.operand;
	return (*this);	
}

/******************************************************************************/
/*                                Nested Class                                */
/******************************************************************************/

const char* RPN::syntaxError::what() const throw() { return "syntax error."; }




void RPN::calculus(std::string arg)
{
	int i = 0;

	while (arg[i])
	{
		while (arg[i] && arg[i] == ' ')
			i++;
		if (!arg[i])
			break;
		else if (arg[i] == '+')
			arithAdd();
		else if (arg[i] == '-')
			arithSub();
		else if (arg[i] == '*')
			arithMul();
		else if (arg[i] == '/')
			arithDiv();
		else
		 	chToD(arg[i]);
		i++;
		if (arg[i] && arg[i] != ' ')
			throw syntaxError();
	}
	if (operand.size() != 1)
		throw syntaxError();
	std::cout << GREEN << "result: " << DEFAULT << operand[0] << std::endl;
}

void RPN::chToD(char ch)
{
	int val = ch - '0';
	if (val < 0 || val > 9)
		throw syntaxError();
	this->operand.push_back(static_cast<double>(val));
}

void RPN::arithAdd(void)
{
	int size = operand.size();

	if (size < 2)
        throw syntaxError();
    double result;
	result = operand[size - 2] + operand[size - 1];
    operand.pop_back();
    operand.pop_back();
    operand.push_back(result);
}

void RPN::arithSub(void)
{
	int size = operand.size();

	if (size < 2)
        throw syntaxError();
    double result;
	result = operand[size - 2] - operand[size - 1];
    operand.pop_back();
    operand.pop_back();
    operand.push_back(result);
}

void RPN::arithMul(void)
{
	int size = operand.size();

	if (size < 2)
        throw syntaxError();
    double result;
	result = operand[size - 2] * operand[size - 1];
    operand.pop_back();
    operand.pop_back();
    operand.push_back(result);
}

void RPN::arithDiv(void)
{
	int size = operand.size();

	if (size < 2)
        throw syntaxError();
    double result;
	result = operand[size - 2] / operand[size - 1];
    operand.pop_back();
    operand.pop_back();
    operand.push_back(result);
}
