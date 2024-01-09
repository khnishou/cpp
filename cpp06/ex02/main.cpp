#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate() {
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 10;

    switch (random) {
        case 0:
			std::cout << BLUE << "A generated" << DEFAULT << std::endl;
            return new A();
        case 1:
			std::cout << BLUE << "B generated" << DEFAULT << std::endl;
            return new B();
        default:
			std::cout << BLUE << "C generated" << DEFAULT << std::endl;
            return new C();
    }
}

void identify(Base* p) {
	std::cout << YELLOW << "Identify by pointer:" << DEFAULT << std::endl;
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
	std::cout << YELLOW << "Identify by reference:" << DEFAULT << std::endl;
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {
		// std::cout << "not A\n";
    }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {
		// std::cout << "not B\n";
    }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {
		// std::cout << "not C\n";
    }
}

int main() {
    Base* object = generate();
    identify(object);
    identify(*object);
    delete object;

    return 0;
}