
#pragma once

#include <deque>
#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>


#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

class PmergeMe {
   private:
	std::deque<int> deq;
	std::deque<int> vec;
	
   public:
	PmergeMe(int argc, char* arg[]);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe & operator=(const PmergeMe &other);

	void sortVec();
	void sortDeq();

	template<typename container,typename pair_container>
	container	ft_ford_johnsen(container& numbers,pair_container&  pairs);

	template<typename Container, typename PairContainer>
	void init_pairs(const Container& numbers, PairContainer& pairs);

	template<typename pair_container>
	void merge(pair_container& arr, int p, int q, int r);

	template<typename pair_container>
	void mergeSort(pair_container& arr, int l, int r);

	template<typename container,typename pair_container>
	void	fill(container& main_c,container& pend_c,pair_container&  pairs);

	template<typename container>
	void binary_search_insertion(container& main_c, int num);

	template<typename container>
	container	iterate(container main_c,container pend_c);

	class syntaxError : public std::exception {
		virtual const char* what() const throw();
	};
};
std::ostream & operator<<(std::ostream & o, std::deque<int> const &deq);
std::ostream & operator<<(std::ostream & o, std::vector<int> const &vec);