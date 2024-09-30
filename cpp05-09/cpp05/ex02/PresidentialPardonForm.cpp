#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Member Functions

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

// Constructors

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Default", 25, 5, "Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getTarget())
{}

// Deconstructor

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& aform)
{
     os << "Form: " << aform.getName()
        << ", Signed: " << (aform.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << aform.getGradeToSign()
        << ", Grade to execute: " << aform.getGradeToExecute()
        << ", Target: " << aform.getTarget();
    return os;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& aform)
{
    if (this != &aform)
    {
        this->setSign(aform.isSigned());
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}