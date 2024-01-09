
#include "Serializer.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

Serializer::Serializer()
{

}

Serializer::Serializer(Serializer const& other)
{
	(void) other;
}

Serializer::~Serializer()
{

}

Serializer& Serializer::operator=(Serializer const& other)
{
	(void) other;
	return (*this);
}

/******************************************************************************/
/*                               Other Function                               */
/******************************************************************************/

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

