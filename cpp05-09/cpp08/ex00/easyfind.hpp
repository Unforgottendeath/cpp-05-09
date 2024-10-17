#pragma once

#include <exception>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found!";
    }
};

#include "easyfind.tpp"