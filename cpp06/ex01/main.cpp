
#include "Serializer.hpp"
#include <iostream>

int main() {
	Serializer serializer;
	Data *data = new Data;
	Data *data2;
	uintptr_t raw;

	data->str = "Up";
	data->num = 42;
	data->ch = 'J';
	data->flt = 42.42f;
	data->dbl = 42.42;

	raw = serializer.serialize(data);

	std::cout << GREEN << "Serial representation: " << DEFAULT << raw << std::endl;
	std::cout << std::endl;
	data2 = serializer.deserialize(raw);
	std::cout  << BLUE << "string: " << DEFAULT << data2->str << std::endl;
	std::cout  << BLUE << "int   : " << DEFAULT << data2->num << std::endl;
	std::cout  << BLUE << "char  : " << DEFAULT << data2->ch << std::endl;
	std::cout  << BLUE << "float : " << DEFAULT << data2->flt << 'f' << std::endl;
	std::cout  << BLUE << "double: " << DEFAULT << data2->dbl << std::endl;

	delete data;
	return 0;
}