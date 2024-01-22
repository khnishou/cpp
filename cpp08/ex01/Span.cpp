
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

const char* Span::OutOfElements::what() const throw() { return "Out of elements"; }
const char* Span::NotEnoughElements::what() const throw() { return "Not enough elements"; }

//****************************************************************************//
//                              Accessor Methods                              //
//****************************************************************************//

void Span::addNumber(int nbr)
{
	if (this->size <= vec.size())
		throw OutOfElements();
	vec.push_back(nbr);
}

//****************************************************************************//
//                               Other Function                               //
//****************************************************************************//

unsigned int Span::shortestSpan() const
{
	int minSpan;
	unsigned int j;
	unsigned int k;
	int span;

	if (vec.size() < 2)
		throw NotEnoughElements();
	minSpan = std::abs(vec[0] - vec[1]);
	j = 0;
	while (j < vec.size())
	{
		k = j;
		while (++k < vec.size())
		{
			span = std::abs(vec[j] - vec[k]);
			if (span < minSpan)
				minSpan = span;
		}
		j++;
	}
	return (minSpan);

}

unsigned int Span::longestSpan() const
{
	int maxSpan;
	unsigned int j;
	unsigned int k;
	int span;

	if (vec.size() < 2)
		throw NotEnoughElements();
	maxSpan = std::abs(vec[0] - vec[1]);
	j = 0;
	while (j < vec.size())
	{
		k = j;
		while (++k < vec.size())
		{
			span = std::abs(vec[j] - vec[k]);
			if (span > maxSpan)
				maxSpan = span;
		}
		j++;
	}
	return (maxSpan);
}
