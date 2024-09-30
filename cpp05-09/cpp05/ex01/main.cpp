#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        std::cout << YELLOW << "<------------------Testing Form class:------------------>" << RESET << std::endl;

        try {
            Bureaucrat bob("Bob", 50);
            Form formA("Form A", 45, 75);
            Form formB("Form B", 20, 30);
            
            std::cout << formA << std::endl;
            bob.signForm(formA);
            
            std::cout << formB << std::endl;
            bob.signForm(formB);
        } catch (const std::exception& e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    return 0;
}