#include "Span.hpp"

// Default constructor
Span::Span() : N(0)
{
    std::cout << GREEN << "Default constructor called !" << RESET << std::endl;
}

// Parameterized constructor
Span::Span(unsigned int n) : N(n)
{
    std::cout << GREEN << "Parameterized constructor called !" << RESET << std::endl;
}

// Copy constructor
Span::Span(const Span& other) : N(other.N), numbers(other.numbers)
{
    std::cout << GREEN << "Copy constructor called !" << RESET << std::endl;
}

// Destructor
Span::~Span()
{
    std::cout << RED << "Destructor called !" << RESET << std::endl;
}

// Copy assignment operator
Span& Span::operator=(const Span& other)
{
    std::cout << GREEN << "copy assignment operator called !" << RESET << std::endl;
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

// Methods
void Span::addNumber(int number)
{
    if (numbers.size() >= N) {
        throw std::length_error("Cannot add more numbers, Span is full.");
    }
    numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}