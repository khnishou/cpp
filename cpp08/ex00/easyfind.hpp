
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int n) {
    typename T::iterator it;

	it = std::find(cont.begin(), cont.end(), n);
    if (it != cont.end()) {
        return it;
    } else {
        throw std::runtime_error("Value not found in container");
    }
}

