#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm()
    : Form("Default", 72, 45, "Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getTarget())
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

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& Form)
{
     os << "Form: " << Form.getName()
        << ", Signed: " << (Form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << Form.getGradeToSign()
        << ", Grade to execute: " << Form.getGradeToExecute()
        << ", Target: " << Form.getTarget();
    return os;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& Form)
{
    if (this != &Form)
    {
        this->setSign(Form.isSigned());
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}