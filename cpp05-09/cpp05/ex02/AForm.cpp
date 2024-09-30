#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors

AForm::AForm(const std::string &name, int signGrade, int execGrade, const std::string &target)
        : Name(name), Signed(false), GradeToSign(signGrade), GradeToExecute(execGrade), Target(target) 
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw GradeTooHighException();
    if (GradeToSign > 150 || GradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

AForm::AForm()
        : Name("Default") , Signed(false) , GradeToSign(75) , GradeToExecute(75) , Target("Default")
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

AForm::AForm(const AForm& form) 
        : Name(form.Name) , Signed(form.Signed) , GradeToSign(form.GradeToSign) , GradeToExecute(form.GradeToExecute) , Target(form.Target)
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

// Deconstructor

AForm::~AForm()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Operator overload

std::ostream& operator<<(std::ostream& os, AForm& aform)
{
     os << "Form: " << aform.getName()
        << ", Signed: " << (aform.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << aform.getGradeToSign()
        << ", Grade to execute: " << aform.getGradeToExecute()
        << ", Target: " << aform.getTarget();
    return os;
}

AForm& AForm::operator=(const AForm& aform)
{
    if (this != &aform)
    {
        this->Signed = aform.Signed;
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}

// Exceptions

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

// Getters

const std::string& AForm::getName() const {
    return Name;
}

bool AForm::isSigned() const {
    return Signed;
}

const int& AForm::getGradeToSign() const {
    return GradeToSign;
}

const int& AForm::getGradeToExecute() const {
    return GradeToExecute;
}

const std::string& AForm::getTarget() const{
    return Target;
}

// Setters

void AForm::setSign(bool sign)
{
    Signed = sign;
}

// Member Functions

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw GradeTooLowException();
    Signed = true;
}