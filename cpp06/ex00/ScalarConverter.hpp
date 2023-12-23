
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <string>
#include <climits>
#include <cfloat>

class ScalarConverter {
   private:
	   int strToD(std::string str, double* out);
      void argsPrint(double val);
      void charPrint(double val);
      void intPrint(double val);
      void floatPrint(double val);
      void doublePrint(double val);
      int chtod(std::string str, double* out);

   public:
	   void convert(std::string input);
};
