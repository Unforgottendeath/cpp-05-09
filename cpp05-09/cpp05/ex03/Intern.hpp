#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern : public AForm
{
    public:
        // Constructors
        Intern();
        Intern(Intern const & intern);

        // Deconstructor
        ~Intern();

        // Member Functions
        AForm* makeForm(std::string const & formName, std::string const & formTarget);
};