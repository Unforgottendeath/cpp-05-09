#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Form.hpp"
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public Form {

    public:
        // Constructors
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& copy);

        // Deconstructor
        ~RobotomyRequestForm();

        // Member Functions
        void execute(const Bureaucrat &executor) const;

        // Operator overload
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& instance);