
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <string.h>
// #include <fstream>

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

template<typename Container, typename PairContainer>
void init_pairs(const Container& numbers, PairContainer& pairs)
{
	typedef typename Container::const_iterator Iterator;
	for (Iterator iter = numbers.begin(); iter != numbers.end(); std::advance(iter, 2))
	{
		Iterator next = std::next(iter);
		std::pair<int, int> tmp;
		if (next != numbers.end())
		{
			tmp.first = std::max(*iter, *next);
			tmp.second = std::min(*iter, *next);
		}
		else
		{
			tmp.first = -1;
			tmp.second = *iter;
		}
		pairs.push_back(tmp);
	}
}

template<typename pair_container>
void merge(pair_container& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<typename pair_container::value_type> L(arr.begin() + p, arr.begin() + p + n1);
	std::vector<typename pair_container::value_type> M(arr.begin() + q + 1, arr.begin() + q + 1 + n2);
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
	{
		if ((L[i].first <= M[j].first && L[i].first != -1) || M[j].first == -1)
			arr[k++] = L[i++];
		else
			arr[k++] = M[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = M[j++];
}

template<typename pair_container>
void mergeSort(pair_container& arr, int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

template<typename container>
void binary_search_insertion(container& main_c, int num)
{
	typename container::iterator low = main_c.begin();
	typename container::iterator high = main_c.end();
	while (low < high)
	{
		typename container::iterator mid = low + (std::distance(low, high) / 2);
		if (*mid < num)
			low = mid + 1;
		else
		{
			high = mid;
		}
	}
	main_c.insert(low, num);
}

template<typename container>
container	iterate(container main_c,container pend_c)
{
	container result(main_c);
	typename container::const_iterator iter = pend_c.begin();
	for (int i = 1, j = 1, counter = 0; counter < static_cast<int>(pend_c.size() - 1);)
	{
		for (size_t k = i; k > j; k--)
		{
			if (k < pend_c.size() + 1)
			{
				counter++;
				binary_search_insertion(result, iter[k - 1]);
			}
		}
		int tmp = i;
		i = i + 2 * j;
		j = tmp;
	}
	return (result);
}

template<typename container,typename pair_container>
container	ft_ford_johnsen(container& numbers,pair_container&  pairs)
{
	container main_c;
	container pend_c;

	init_pairs(numbers,pairs);
	pair_container sorted(pairs.size());
	mergeSort(pairs,0,pairs.size()-1);
	fill(main_c,pend_c,pairs);
	return(iterate(main_c,pend_c));
}

std::vector<int> sortVec(std::vector<int>& numbers)
{
    std::vector<std::pair<int,int> > pairs(0);
	return(ft_ford_johnsen(numbers,pairs));
}

std::deque<int> sortDeq(std::deque<int>& numbers)
{
    std::vector<std::pair<int,int> > pairs(0);
	return(ft_ford_johnsen(numbers,pairs));
}

int main(int argc, char* argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;
    struct timeval vecStart;
    struct timeval vecEnd;
    struct timeval deqStart;
    struct timeval deqEnd;
    unsigned int i = 1;

    if (argc == 2)
    {
		std::cout << "Before : ";
        while (i < argc)
		{
			int num = atoi(argv[i]);
			if (num == 0 && strcmp(argv[i], "0") != 0)
				throw(std::string("Error : isnotnumeric"));
			if (num < 0)
				throw(std::string("Error : number < 0"));
			std::cout << num << " " << std::endl;
            vec.push_back(num);
			deq.push_back(num);
            i++;
		}

        gettimeofday(&vecStart,NULL);
        sortVec(vec);
        gettimeofday(&vecEnd,NULL);


        gettimeofday(&deqStart,NULL);
        sortDeq(deq);
        gettimeofday(&deqEnd,NULL);
    }
    else
		std::cerr << RED << "Error: " << DEFAULT << "Incorrect number of arguments provided" << std::endl;
}