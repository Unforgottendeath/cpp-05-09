#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

class PMergeMe {
public:
    PMergeMe();
    ~PMergeMe();
    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);
    template <typename T>
    static void	print(char **av, T container);
    template <typename T>
    static void sort(T &container, size_t pair_level);
    template <typename T>
    static void swap(T &a, T &b, size_t& pair_level);
    template <typename T, typename F>
    static void	devide_n_conquer(T & main, F & pend, F & new_main, F & oddElement, T & leftOvers, size_t pair_level);
    template <typename T, typename F>
    static void	rebuild_main(T & main, F & new_main, T & leftOvers, size_t element_size);
    template <typename T>
    static void sortvec(std::vector<T> &vec);
    template <typename T>
    static void sortqueue(std::deque<T> &queue);
};

bool	is_number(std::string nbr);
int	jacobsthal(int index);

#endif // __PMERGE_ME_HPP__