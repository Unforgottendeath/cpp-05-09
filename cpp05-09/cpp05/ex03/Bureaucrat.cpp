#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors

Bureaucrat::Bureaucrat(const std::string& _Name, const int& _Grade) : Name(_Name) , Grade(_Grade)
{
    if (Grade < 1)
        throw Form::GradeTooHighException();
    if (Grade > 150)
        throw Form::GradeTooLowException();
    std::cout << GREEN << "Created: "<< *this << RESET << std::endl;
}

Bureaucrat::Bureaucrat() : Name("Default") , Grade(75)
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : Name(copy.Name) , Grade(copy.Grade)
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

// Deconstructors

Bureaucrat::~Bureaucrat()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Getters

const std::string& Bureaucrat::getName(void) const
{
    return Name;
}

const int& Bureaucrat::getGrade(void) const
{
    return Grade;
}

// Operator overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
        this->Grade = copy.Grade;
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}

// Member Functions

void Bureaucrat::signForm(Form &form)
{
        form.beSigned(*this);
        std::cout << Name << " signed " << form.getName() << "\n";
}

void Bureaucrat::executeForm(Form &form)
{
    try {
        form.execute(*this);
        std::cout << Name << " executed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cout << RED << Name << " could not execute " << form.getName() << " because: " << e.what() << RESET << "\n";
    }
}