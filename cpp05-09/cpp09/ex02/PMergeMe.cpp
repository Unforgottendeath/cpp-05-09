#include "PMergeMe.hpp"
#include "PMergeMe.tpp"

PMergeMe::PMergeMe() {
    // Constructor
}

PMergeMe::~PMergeMe() {
    // Destructor
}

PMergeMe::PMergeMe(const PMergeMe &other) {
    (void)other;
    // Copy constructor
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
    // Assignment operator
    (void)other;
    return *this;
}

bool	is_number(std::string nbr)
{
	for (int i = 0; nbr[i]; i++)
		if (std::isdigit(nbr[i]) == 0)
			return false;
	return true;
}

int	jacobsthal(int index)
{
	return (int)( (pow(-1, index-1) + pow(2, index)) / 3 );
}