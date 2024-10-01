#pragma once

#include <iostream>
#include <string>

class Form;

class Intern
{
    public:
        // Constructors
        Intern();
        Intern(Intern const & intern);

        // Deconstructor
        ~Intern();

        // Member Functions
        Form* makeForm(std::string const & formName, std::string const & formTarget);

        // Operator overload
        Intern & operator=(const Intern &src);
};