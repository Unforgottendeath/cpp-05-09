#include "Bureaucrat.hpp"

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

Bureaucrat::~Bureaucrat()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

const std::string& Bureaucrat::getName(void)
{
    return Name;
}

const int& Bureaucrat::getGrade(void)
{
    return Grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException \n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException \n";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::incrementGrade(void)
{
    if (Grade <= 1)
        throw GradeTooHighException();
    --Grade;
    std::cout << "After increment: " << *this  << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
    if (Grade >= 150)
        throw GradeTooLowException();
    ++Grade;
    std::cout << "After decrement: " << *this << std::endl;
}