#include "MutantStack.hpp"

// Default constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// Copy assignment operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

// Iterator functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}
