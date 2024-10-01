#pragma once

#include <iostream>
#include <string>

class Form;

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
        void                signForm(Form& form);
        void                executeForm(Form& form);

        // Operator overload
        Bureaucrat& operator=(const Bureaucrat& copy);
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);