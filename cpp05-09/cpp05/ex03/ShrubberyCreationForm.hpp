#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form {

    public:
        // Constructors
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);

        // Deconstructor
        ~ShrubberyCreationForm();

        // Member Functions
        void execute(const Bureaucrat &executor) const;

        // Operator overload
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& instance);