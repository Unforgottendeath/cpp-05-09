#pragma once

#include <string>
#include <exception>
#include <iostream>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

class Bureaucrat;

class AForm {
private:
    const std::string   Name;
    bool                Signed;
    const int           GradeToSign;
    const int           GradeToExecute;
    const std::string   Target;

public:

    // Constructors
    AForm(const std::string &name, int signGrade, int execGrade, const std::string &target);
    AForm();
    AForm(const AForm& copy);

    // Deconstructor
    virtual ~AForm();

    // Getters
    const std::string&  getName(void) const ;
    const int&          getGradeToExecute(void) const;
    const int&          getGradeToSign(void) const;
    bool                isSigned() const;
    const std::string&  getTarget() const;

    // Setters
    void                setSign(bool sign);

    // Member Functions
    void                beSigned(const Bureaucrat &bureaucrat);
    virtual void        execute(const Bureaucrat &executor) const = 0; // Pure virtual function

    // Operator overload
    AForm& operator=(const AForm& Form);

    // Exceptions
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, AForm& aform);