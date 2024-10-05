#pragma once

#include <string>
#include <iostream>
#include <exception>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

template <typename T>

void swap(T& a, T& b)
{
    T c;
    
    c = a;
    a = b;
    b = c;
}

template<typename T>

T Min(const T& a, const T& b)
{
    return (b <= a ? b : a);
}

template<typename T>

T Max(const T& a,const T& b)
{
    return (b >= a ? b : a);
}