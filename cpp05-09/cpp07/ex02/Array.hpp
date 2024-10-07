#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
    private:
        T*              data;
        unsigned int    size_;

    public:
        // Constructors
        Array();                 
        Array(unsigned int n);          
        Array(const Array& other);

        // Operator overload
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        // Member Functions
        unsigned int size() const;

        // Decontructor
        ~Array();                         // Destructor
};

#include "Array.tpp"
