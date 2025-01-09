#ifndef PMERGEME_TPP
#define PMERGEME_TPP
#include "PMergeMe.hpp"

template <typename T>
void	PMergeMe::swap(T & start1, T & start2, size_t& pair_level)
{
	T it1 = start1;
	T it2 = start2;
	for (size_t	i = 0; i != pair_level / 2; i++)
	{
		std::swap(*it1, *it2);
		it1--;
		it2--;
	}
}

template <typename T, typename F>
void	PMergeMe::rebuild_main(T & main, F & new_main, T & leftOvers, size_t element_size)
{
	T main_copy;
	typename F::iterator it = new_main.begin();

	// We insert into main_copy the numbers pointed to by the iterators in new_main along with whatever other numbers are paired
	// to it on this recursion level

	while (it != new_main.end())
	{
		main_copy.insert(main_copy.end(), (*it) - (element_size - 1), (*it) + 1);
		it++;
	}

	// We insert any leftovers

	main_copy.insert(main_copy.end(), leftOvers.begin(), leftOvers.end());

	main = main_copy;
}

template <typename T, typename F>
void	insert(T & pend, T & new_main, T & oddElement, F copy)
{
	typename F::iterator copy_it;

	// We put in copy the numbers pointed to by each interator in new_main

	for (typename T::iterator itr = new_main.begin(); itr != new_main.end(); itr++)
		copy.push_back(**itr);

	// If there is only one element in pend, we insert normally since jacobsthal does not apply

	if (pend.size() == 1)
	{
		copy_it = std::upper_bound(copy.begin(), copy.end() - 1, **(pend.begin()));
		new_main.insert(new_main.begin() + (copy_it - copy.begin()), *(pend.begin()));
		copy.insert(copy_it, **(pend.begin()));
	}

	// If there are more than one element in pend then we insert using jacobsthal to set the order of insertion

	else if (pend.size() > 1)
	{
		size_t jacobsthal_index = 3;
		size_t count = 0;
		size_t index;
		size_t decrease;
		while (!pend.empty())
		{
			// We use jacobsthal to get the index of the element we will first insert

			index = jacobsthal(jacobsthal_index) - jacobsthal(jacobsthal_index - 1);
			if (index > pend.size())
				index = pend.size();

			// We then insert the element at index and anything before it

			decrease = 0;
			while (index != 0)
			{
				// We calculate where we can limit our search area for binary search to use less comparisions

				if ((jacobsthal(jacobsthal_index) + count) - decrease <= copy.size())
					copy_it = copy.begin() + (jacobsthal(jacobsthal_index) + count) - decrease;
				else
					copy_it = copy.end();

				// We use upper_bound to find where to insert the element at index

				copy_it = std::upper_bound(copy.begin(), copy_it, **(pend.begin() + index - 1));

				// We then insert the iterator element into the new_main, the number element into copy, and remove the iterator element from pend

				new_main.insert(new_main.begin() + (copy_it - copy.begin()), *(pend.begin() + index - 1));
				copy.insert(copy_it, **(pend.begin() + index - 1));
				pend.erase(pend.begin() + index - 1, pend.begin() + index);

				count++;
				decrease++;
				index--;
			}
			jacobsthal_index++;
		}
	}

	// If there is an odd element we insert it to the new_main

	if (!oddElement.empty())
	{
		copy_it = std::upper_bound(copy.begin(), copy.end(), **(oddElement.begin()));
		new_main.insert(new_main.begin() + (copy_it - copy.begin()), *(oddElement.begin()));
	}
}

template <typename T, typename F>
void	PMergeMe::devide_n_conquer(T & main, F & pend, F & new_main, F & oddElement, T & leftOvers, size_t pair_level)
{
	typename T::iterator it = main.begin();
	typename T::iterator end = it + (pair_level - 1);
	typename T::iterator start = it + (pair_level / 2) - 1;
	size_t element_size = pair_level / 2;
	size_t nb_it = 0;

	// We put into the new main the first pair a1 and b1

	new_main.push_back(it + element_size - 1);
	new_main.push_back(end);

	it += pair_level;
	nb_it += pair_level;

	while (nb_it < main.size())
	{
		// If there is a full pair then we devide ax and bx into pend and new_main respectively

		 if (nb_it + (pair_level - 1) < main.size())
		 {
		 	start = it + (pair_level / 2) - 1;
		 	end = it + (pair_level - 1);

		 	pend.push_back(start);
		 	new_main.push_back(end);
		 }

		// If not then we are at the end of our array

		else
		{
			// If there is an odd element (not a full pair) then we put it in OddElement

			if (nb_it + element_size - 1 < main.size())
			{
				oddElement.push_back(it + element_size - 1);
				it += element_size;
			}

			// If there are some integers left but not enough to make up an element we put it in the leftOvers vector

			if (nb_it < main.size())
				leftOvers.insert(leftOvers.end(), it, main.end());
			return ;
		}
		if (nb_it + pair_level < main.size())
		{
			it += pair_level;
			nb_it += pair_level;
		}
		else
			return ;

	}
}

template <typename T>
void PMergeMe::sort(T &container, size_t pair_level) {
    typename T::iterator end;
	typename T::iterator start;

	for (typename T::iterator it = container.begin(); it + (pair_level - 1) < container.end(); it += pair_level)
	{
		start = it + (pair_level / 2) - 1;
		end = it + (pair_level - 1);
        std::cout << "before swap: ";
        for (typename T::iterator iterator = it; iterator <= end; ++iterator) {
            std::cout << *iterator << " ";
        }
		if (*start > *end)
			swap(start, end, pair_level);
        std::cout << "after swap: ";
        for (typename T::iterator iterator = it; iterator <= end; ++iterator) {
            std::cout << *iterator << " ";
        }
        std::cout << std::endl;
	}
    std::cout << "final result: ";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
	if (container.size() / pair_level >= 2)
		sort(container, pair_level * 2);
    std::vector<typename T::iterator> pend;
	std::vector<typename T::iterator> new_main;
	std::vector<typename T::iterator> oddElement;
	T leftOvers;
	size_t element_size = pair_level / 2;

	devide_n_conquer(container, pend, new_main, oddElement, leftOvers, pair_level);
    std::cout << "pend: ";
    for (typename std::vector<typename T::iterator>::iterator it = pend.begin(); it != pend.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    std::cout << "new_main: ";
    for (typename std::vector<typename T::iterator>::iterator it = new_main.begin(); it != new_main.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    std::cout << "oddElement: ";
    for (typename std::vector<typename T::iterator>::iterator it = oddElement.begin(); it != oddElement.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    std::cout << "leftOvers: ";
    for (typename T::iterator it = leftOvers.begin(); it != leftOvers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // if there is something in pend or odd we insert them in the new Main

	if (!pend.empty() || !oddElement.empty())
	{
		T copy;
		insert(pend, new_main, oddElement, copy);

		// We then use new_main (a vector of iterators) to build the main (a vector of integers)

		rebuild_main(container, new_main, leftOvers, element_size);
	}
}


template <typename T>
bool is_exclusive(T & container, size_t nb)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		if (*it == nb)
			return false;
	return true;
}

template <typename T>
void	PMergeMe::print(char **av, T container)
{
	std::cout << "Before :";
	for (int i = 1; av[i]; i++)
		std::cout << " " << av[i];
	std::cout << std::endl;
	std::cout << "After :";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename T>
void	parse(char **input, T & container)
{
	int	i = 1;
	while (input[i])
	{
		size_t	tmp = 0;
		if (!is_number(input[i]))
			throw std::invalid_argument("PmergeMe only accepts positive numbers");
		tmp = static_cast<size_t>(atof(input[i]));
		if (!is_exclusive(container, tmp))
			throw std::invalid_argument("PmergeMe does not accept duplicate numbers");
		container.push_back(tmp);
		i++;
	}
}

template <typename T>
void PMergeMe::sortvec(std::vector<T> &vec) {
    sort(vec, 2);
}

template <typename T>
void PMergeMe::sortqueue(std::deque<T> &queue) {
    sort(queue, 2);
}
#endif // PMERGEME_TPP