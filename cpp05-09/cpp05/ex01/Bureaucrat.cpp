#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors

Bureaucrat::Bureaucrat(const std::string& _Name, const int& _Grade) : Name(_Name) , Grade(_Grade)
{
    if (Grade < 1)
        throw GradeTooHighException();
    if (Grade > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Created: "<< *this << RESET << std::endl;
}

Bureaucrat::Bureaucrat() : Name("Default") , Grade(75)
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
        this->Grade = copy.Grade;
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
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

// Exceptions

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException \n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException \n";
}

// Operator overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

// Member Functions

void Bureaucrat::incrementGrade(void)
{
    if (Grade <= 1)
        throw GradeTooHighException();
    --Grade;
    std::cout << GREEN << "After increment: " << *this << RESET << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
    if (Grade >= 150)
        throw GradeTooLowException();
    ++Grade;
    std::cout << GREEN << "After decrement: " << *this << RESET << std::endl;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << Name << " signed " << form << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << RED << Name << " couldn't sign " << form << " because " << e.what() << RESET << std::endl;
    }
}