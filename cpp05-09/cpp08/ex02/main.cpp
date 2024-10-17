#include "MutantStack.hpp"

int main() {
    MutantStack<int> ms;
    
    ms.push(1);
    ms.push(2);
    ms.push(3);
    
    std::cout << "MutantStack contents:" << std::endl;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << std::endl; // Output: 1, 2, 3
    }

    // Testing with std::list for comparison
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "List contents:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl; // Output: 1, 2, 3
    }

    return 0;
}