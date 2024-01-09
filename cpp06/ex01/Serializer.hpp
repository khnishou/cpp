
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <string>

struct Data {
	std::string str;
	int num;
	char ch;
	float flt;
	double dbl;
};

class Serializer {
   public:
	~Serializer();
	Serializer();
	Serializer(Serializer const& other);
	Serializer& operator=(Serializer const& other);

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};
