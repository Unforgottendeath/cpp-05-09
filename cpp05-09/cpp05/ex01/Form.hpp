#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:

        const std::string   Name;
        bool                Signed;
        const int           GradeToSign;
        const int           GradeToExecute;

    public:

        // Constructors
        Form(const std::string& _Name, const int& _GradetoSign, const int& _GradetoExecute );
        Form();
        Form(const Form &copy);

        // Deconstructor
        virtual             ~Form();

        // Getters
        const std::string&  getName(void) const ;
        const int&          getGradeToExecute(void) const;
        const int&          getGradeToSign(void) const;
        bool                isSigned() const;

        // Operator overload
        Form& operator=(const Form& Form);

        // Member functions
        void beSigned(Bureaucrat& bureaucrat);

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);