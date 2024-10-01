#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << YELLOW << "<------------------Testing AForm class:------------------>" << RESET << std::endl;
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    delete rrf;
    return 0;
}