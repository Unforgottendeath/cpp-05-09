#pragma once

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

#include <iostream>
#include <string>

template <typename T>

void iter(T* array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}