#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

class Bureaucrat
{

    private:
        const std::string   Name;
        int                 Grade;

    public:
        // Constructors
        Bureaucrat(const std::string& _Name, const int& _Grade);
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);

        // Deconstructor
        ~Bureaucrat();

        // Getters
        const std::string&  getName(void) const;
        const int&          getGrade(void) const;

        // Members functions
        void                incrementGrade(void);
        void                decrementGrade(void);
        void                signForm(Form& form);

        // Operator overload
        Bureaucrat& operator=(const Bureaucrat& copy);

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

std::ostream& operator<<(std::ostream& os, Bureaucrat& copy);