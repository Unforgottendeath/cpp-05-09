#pragma once

#include <iostream>
#include <stack>
#include <iterator>
#include <list>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Constructors
    MutantStack();
    MutantStack(const MutantStack& other);
    
    // Destructor
    ~MutantStack();

    // Copy assignment operator
    MutantStack& operator=(const MutantStack& other);

    // Iterator functions
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    using std::stack<T>::push;
    using std::stack<T>::pop;
    using std::stack<T>::top;
    using std::stack<T>::empty;
    using std::stack<T>::size;
};

#include "MutantStack.tpp"

