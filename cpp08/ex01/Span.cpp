
#include "Span.hpp"

//****************************************************************************//
//                          Constructor & Destructor                          //
//****************************************************************************//

Span::Span(unsigned int N) : size(N) {}

Span::~Span() {}

Span::Span(Span const& other) : vec(other.vec), size(other.size) {}

// ************************************************************************** //
//                               OPERATOR OVERLOAD                            //
// ************************************************************************** //

Span& Span::operator=(const Span& other) {
	vec = other.vec;
	size = other.size;
	return (*this);
}

/******************************************************************************/
/*                                Nested Class                                */
/******************************************************************************/

const char* Span::TooManyElements::what() const throw() { return "Too many elements"; }
const char* Span::NotEnoughElements::what() const throw() { return "Not enough elements"; }

//****************************************************************************//
//                              Accessor Methods                              //
//****************************************************************************//

void Span::addNumber()
{

}

//****************************************************************************//
//                               Other Function                               //
//****************************************************************************//

unsigned int Span::shortestSpan()
{

}

unsigned int Span::longestSpan()
{
	
}