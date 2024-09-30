#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

    public:
        // Constructors
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& copy);

        // Deconstructor
        ~PresidentialPardonForm();

        // Member Functions
        void execute(const Bureaucrat &executor) const;

        // Operator overload
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& instance);