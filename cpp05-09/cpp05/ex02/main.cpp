#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(static_cast<unsigned>(std::time(NULL)));
    std::cout << YELLOW << "<------------------Testing AForm class:------------------>" << RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 150);
        AForm *f = new RobotomyRequestForm();
        f->execute(bob);
    } catch (const std::exception &e) {
        delete f;
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    return 0;
}