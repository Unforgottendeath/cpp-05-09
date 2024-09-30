#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << YELLOW << "<------------------Testing AForm class:------------------>" << RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Charlie");

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    return 0;
}