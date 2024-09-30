#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors

Form::Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute)
        : Name(name), Signed(false), GradeToSign(gradeToSign), GradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Form::Form()
        : Name("Default") , Signed(false) , GradeToSign(75) , GradeToExecute(75){
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

Form::Form(const Form& form) 
        : Name(form.Name) , Signed(form.Signed) , GradeToSign(form.GradeToSign) , GradeToExecute(form.GradeToExecute){
    std::cout << GREEN << "Created: " << *this << RESET << std::endl;
}

// Deconstructor

Form::~Form(){
    std::cout << ORANGE << "WIPE: " << *this << RESET << std::endl;
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

// Operator overload

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute();
    return os;
}

Form& Form::operator=(const Form& form)
{
    if (this != &form)
    {
        this->Signed = form.Signed;
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

// Member Functions

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= GradeToSign) {
        Signed = true;
    } else {
        throw GradeTooLowException();
    }
}