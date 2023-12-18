
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

class ScalarConverter {
    private:
        int atod(std::sring str);
        int itod(std::sring str);
        int dtod(std::sring str);
        int ftod(std::sring str);

    public:
        void convert(std::string input);
}