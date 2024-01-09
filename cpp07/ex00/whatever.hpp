
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T& min(T& a, T& b)
{
    if (a < b)
		return (a);
	return (b);
}

template <typename T>
T& max(T& a, T& b)
{
    if (a > b)
		return (a);
	return (b);
}
