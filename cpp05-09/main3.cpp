#include <iostream>
#include <stack>
#include <iterator>
#include <list>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Type definitions for the iterator and const_iterator
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Push a new element onto the stack
    using std::stack<T>::push;
    
    // Pop an element from the stack
    using std::stack<T>::pop;
    
    // Access the top element
    using std::stack<T>::top;
    
    // Check if the stack is empty
    using std::stack<T>::empty;
    
    // Get the size of the stack
    using std::stack<T>::size;

    // Iterator functions
    iterator begin() {
        return this->c.begin(); // Access the underlying container's begin
    }

    iterator end() {
        return this->c.end(); // Access the underlying container's end
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }
};

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

