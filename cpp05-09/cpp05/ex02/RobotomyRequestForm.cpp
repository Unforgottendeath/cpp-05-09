#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Default", 72, 45, "Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getTarget())
{}

// Deconstructor

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Member Functions

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "Drilling noises...\n";
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy of " << getTarget() << " failed!\n";
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& aform)
{
     os << "Form: " << aform.getName()
        << ", Signed: " << (aform.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << aform.getGradeToSign()
        << ", Grade to execute: " << aform.getGradeToExecute()
        << ", Target: " << aform.getTarget();
    return os;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& aform)
{
    if (this != &aform)
    {
        this->setSign(aform.isSigned());
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}