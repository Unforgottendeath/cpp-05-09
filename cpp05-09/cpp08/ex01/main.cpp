#include "Span.hpp"

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