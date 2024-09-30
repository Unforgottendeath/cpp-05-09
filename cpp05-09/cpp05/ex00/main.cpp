#include "Bureaucrat.hpp"   

void testBureaucrat(const std::string& name, int grade) {
    try {
        Bureaucrat bureaucrat(name, grade);

        bureaucrat.incrementGrade();

        bureaucrat.decrementGrade();

        for (int i = 0; i < 150; ++i) {
            bureaucrat.decrementGrade();
        }
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

int main() {
    {
        std::cout << YELLOW << "<------------------Testing Bureaucrat class:------------------>" << RESET << std::endl;

        testBureaucrat("Alice", 2);
        testBureaucrat("Bob", 1);
        testBureaucrat("Charlie", 150);
    }
    {
        std::cout << YELLOW << "<------------------Testing Bureaucrat class:------------------>" << RESET << std::endl;
        try {
        Bureaucrat bob("Ahmed", 50);
        Bureaucrat alice = bob;
        Bureaucrat charlie("Rabie", 75);
        charlie = bob;

        bob.incrementGrade();

        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}