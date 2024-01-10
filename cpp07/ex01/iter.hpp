
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <iostream>

template <typename T, typename F>
void iter(T* arr,int len, F func) {
    int i;

    i = 0;
    while (i < len) {
        func(arr[i]);
        i++;
    }
}

void printBlue(char c) {
	std::cout << BLUE << c;
}

void printRed(char c) {
	std::cout << RED << c;
}

void printGreen(char c) {
	std::cout << GREEN << c;
}

void printYellow(char c) {
	std::cout << YELLOW << c;
}

void printWhite(char c) {
	std::cout << DEFAULT << c;
}
