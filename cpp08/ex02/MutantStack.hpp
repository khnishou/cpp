#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

#include <iterator>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
   public:
	typedef typename Container::iterator iterator;

	MutantStack() {}
	~MutantStack();
	MutantStack(Container const& other) : std::stack<T, Container>::stack(other) {}
	MutantStack& operator=(Container const& other) { std::stack<T, Container>::operator=(other); }

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
