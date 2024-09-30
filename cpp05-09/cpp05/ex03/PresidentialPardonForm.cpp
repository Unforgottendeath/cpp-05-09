#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
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
    : Form("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm()
    : Form("Default", 25, 5, "Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getTarget())
{}

// Deconstructor

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& Form)
{
     os << "Form: " << Form.getName()
        << ", Signed: " << (Form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << Form.getGradeToSign()
        << ", Grade to execute: " << Form.getGradeToExecute()
        << ", Target: " << Form.getTarget();
    return os;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& Form)
{
    if (this != &Form)
    {
        this->setSign(Form.isSigned());
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}