
#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <cstdlib>
#include <exception>

template <typename T>
class Array {
   private:
	T* _array;
	unsigned int _size;

   public:
	/******************************************************************************/
	/*                          Constructor & Destructor                          */
	/******************************************************************************/
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _size(n) {
		if (n == 0)
			_array = NULL;
		else
			_array = new T[n]();
	}

	~Array() { delete[] _array; }

	Array(Array const& other) {
		_size = other._size;
		if (_size == 0)
			_array = NULL;
		else {
			_array = new T[_size]();
			for (unsigned int i = 0; i < _size; i++) _array[i] = other._array[i];
		}
	}

	/******************************************************************************/
	/*                              Accessor Methods                              */
	/******************************************************************************/

	unsigned int size() const { return _size; };

	/******************************************************************************/
	/*                              Operator Overload                             */
	/******************************************************************************/

	Array& operator=(const Array& other) {
		unsigned int i;
		
		i = 0;
		if (this != &other) {
			delete[] this->_array;
			this->_size = other._size;
			if (this->_size > 0) {
				this->_array = new T[this->_size]();
				while (i < this->_size) this->_array[i] = other._array[i++];
			}
		}
		return *this;
	}

	T& operator[](unsigned int i) {
		if (i >= _size) throw IndexNotFound();
		return _array[i];
	}

	T const& operator[](unsigned int index) const {
		if (index >= _size) throw IndexNotFound();
		return _array[index];
	}

	/******************************************************************************/
	/*                                Nested Class                                */
	/******************************************************************************/

	class IndexNotFound : public std::exception {
	   public:
		char const* what() const throw() { return RED "Index not found\n" DEFAULT; }
	};
};