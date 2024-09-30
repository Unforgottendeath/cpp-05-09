#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors

Form::Form(const std::string &name, int signGrade, int execGrade, const std::string &target)
        : Name(name), Signed(false), GradeToSign(signGrade), GradeToExecute(execGrade), Target(target) 
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw GradeTooHighException();
    if (GradeToSign > 150 || GradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Form::Form()
        : Name("Default") , Signed(false) , GradeToSign(75) , GradeToExecute(75) , Target("Default")
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Form::Form(const Form& form) 
        : Name(form.Name) , Signed(form.Signed) , GradeToSign(form.GradeToSign) , GradeToExecute(form.GradeToExecute) , Target(form.Target)
{
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

// Deconstructor

Form::~Form()
{
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
}

// Operator overload

std::ostream& operator<<(std::ostream& os, Form& Form)
{
     os << "Form: " << Form.getName()
        << ", Signed: " << (Form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << Form.getGradeToSign()
        << ", Grade to execute: " << Form.getGradeToExecute()
        << ", Target: " << Form.getTarget();
    return os;
}

Form& Form::operator=(const Form& Form)
{
    if (this != &Form)
    {
        this->Signed = Form.Signed;
    }
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
    return *this;
}

// Exceptions

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* Form::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

// Getters

const std::string& Form::getName() const {
    return Name;
}

bool Form::isSigned() const {
    return Signed;
}

const int& Form::getGradeToSign() const {
    return GradeToSign;
}

const int& Form::getGradeToExecute() const {
    return GradeToExecute;
}

const std::string& Form::getTarget() const{
    return Target;
}

// Setters

void Form::setSign(bool sign)
{
    Signed = sign;
}

// Member Functions

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw GradeTooLowException();
    Signed = true;
}