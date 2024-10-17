#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <limits>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

class Span {
    private:
        unsigned int N;
        std::vector<int> numbers;

    public:
        // Constructors
        Span(unsigned int n);
        Span(const Span & other);
        Span();

        // Deconstructor
        ~Span();

        // Operator overload
        Span & operator=(const Span & other);

        //Methods
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};