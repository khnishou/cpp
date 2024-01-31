#include "PmergeMe.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

PmergeMe::PmergeMe(int argc, char* argv[])
{
    unsigned int i = 1;

	std::cout << "Before : ";
	while (i < argc)
	{
		int num = atoi(argv[i]);
		if (num == 0 && strcmp(argv[i], "0") != 0)
			throw(std::string("Error : isnotnumeric"));
		if (num < 0)
			throw(std::string("Error : number < 0"));
		std::cout << num << " ";
		this->vec.push_back(num);
		this->deq.push_back(num);
		i++;
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {}

/******************************************************************************/
/*                               OPERATOR OVERLOAD                            */
/******************************************************************************/

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { return (*this); }

std::ostream& operator<<(std::ostream& o, const std::deque<int>& deq) {
    std::deque<int>::const_iterator iter = deq.begin();

    while (iter != deq.end()) {
        o << *iter << " ";
        ++iter;
    }
    o << std::endl;
    return o;
}

std::ostream& operator<<(std::ostream& o, const std::vector<int>& vec) {
    std::vector<int>::const_iterator iter = vec.begin();

    while (iter != vec.end()) {
        o << *iter << " ";
        ++iter;
    }
    o << std::endl;
    return o;
}

/******************************************************************************/
/*                                Nested Class                                */
/******************************************************************************/

const char* PmergeMe::syntaxError::what() const throw() { return "syntax error."; }

/******************************************************************************/
/*                                   others                                   */
/******************************************************************************/

void PmergeMe::sortVec()
{
	struct timeval start;
    struct timeval end;
	struct timeval tmp;

	std::cout << std::endl << std::endl;
	gettimeofday(&start,NULL);
    std::vector<std::pair<int,int> > pairs(0);
	vec = ft_ford_johnsen(vec,pairs);
	gettimeofday(&end,NULL);
	tmp.tv_sec = end.tv_sec - start.tv_sec;
	tmp.tv_usec = end.tv_usec - start.tv_usec;
	while (tmp.tv_usec < 0)
	{
		tmp.tv_sec--;
		tmp.tv_usec += 1000000;
	}
	std::cout << GREEN << "After(vec)[" << (tmp.tv_usec + tmp.tv_sec * 1000000) << "ms] : "<< DEFAULT << vec << std::endl;
}

void PmergeMe::sortDeq()
{
	struct timeval start;
    struct timeval end;
	struct timeval tmp;

	gettimeofday(&start,NULL);
    std::deque<std::pair<int,int> > pairs(0);
	deq = ft_ford_johnsen(deq,pairs);
	gettimeofday(&end,NULL);
	tmp.tv_sec = end.tv_sec - start.tv_sec;
	tmp.tv_usec = end.tv_usec - start.tv_usec;
	while (tmp.tv_usec < 0)
	{
		tmp.tv_sec--;
		tmp.tv_usec += 1000000;
	}
	std::cout << GREEN << "After(deq)[" << (tmp.tv_usec + tmp.tv_sec * 1000000) << "ms] : " << DEFAULT << deq << std::endl;
}

template<typename container,typename pair_container>
container	PmergeMe::ft_ford_johnsen(container& numbers,pair_container&  pairs)
{
	container main_c;
	container pend_c;

	init_pairs(numbers,pairs);
	pair_container sorted(pairs.size());
	mergeSort(pairs,0,pairs.size()-1);
	fill(main_c,pend_c,pairs);
	return(iterate(main_c,pend_c));
}

template<typename Container, typename PairContainer>
void PmergeMe::init_pairs(const Container& numbers, PairContainer& pairs)
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
void PmergeMe::merge(pair_container& arr, int p, int q, int r)
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
void PmergeMe::mergeSort(pair_container& arr, int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

template<typename container,typename pair_container>
void	PmergeMe::fill(container& main_c,container& pend_c,pair_container&  pairs)
{
	for (typename pair_container::const_iterator iter = pairs.begin(); iter != pairs.end(); iter++)
	{
		if (iter->first != -1)
			main_c.push_back(iter->first);
		pend_c.push_back(iter->second);
	}
	
}

template<typename container>
void PmergeMe::binary_search_insertion(container& main_c, int num)
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
container	PmergeMe::iterate(container main_c,container pend_c)
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
