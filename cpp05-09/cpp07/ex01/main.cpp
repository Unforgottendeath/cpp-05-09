#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << GREEN << "Original integer array: ";
    iter(intArray, intLength, printElement);
    std::cout << RESET << std::endl;

    iter(intArray, intLength, incrementElement);
    
    std::cout << YELLOW << "Incremented integer array: ";
    iter(intArray, intLength, printElement);
    std::cout << RESET << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << GREEN << "Original double array: ";
    iter(doubleArray, doubleLength, printElement);
    std::cout << RESET << std::endl;

    iter(doubleArray, doubleLength, incrementElement);
    
    std::cout << YELLOW << "Incremented double array: ";
    iter(doubleArray, doubleLength, printElement);
    std::cout << RESET << std::endl;

    return 0;
}
