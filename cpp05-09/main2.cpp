#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int n) : N(n) {}

    void addNumber(int number) {
        if (numbers.size() >= N) {
            throw std::length_error("Cannot add more numbers, Span is full.");
        }
        numbers.push_back(number);
    }

    int shortestSpan() {
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

    int longestSpan() {
        if (numbers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }
        int max = *std::max_element(numbers.begin(), numbers.end());
        int min = *std::min_element(numbers.begin(), numbers.end());
        return max - min;
    }
};

int main() {
    try {
        Span span(5);
        span.addNumber(1);
        span.addNumber(3);
        span.addNumber(7);
        span.addNumber(15);
        span.addNumber(2);
        
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl; // Output: 1
        std::cout << "Longest span: " << span.longestSpan() << std::endl;   // Output: 14
        
        // Uncommenting the next line should throw an exception
        // span.addNumber(20); // Throws an exception

        // Testing with fewer than two numbers
        Span smallSpan(1);
        // smallSpan.shortestSpan(); // Throws an exception

        // Testing with a large number of inputs
        Span largeSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            largeSpan.addNumber(i);
        }
        std::cout << "Shortest span in large span: " << largeSpan.shortestSpan() << std::endl; // Output: 1
        std::cout << "Longest span in large span: " << largeSpan.longestSpan() << std::endl;   // Output: 9999
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

