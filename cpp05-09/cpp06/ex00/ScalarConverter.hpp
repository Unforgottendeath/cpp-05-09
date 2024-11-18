#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <sstream>

class ScalarConverter
{

    private:
        // Static Member Functions
        static void  handleChar(double d);
        static void handleInt(double d);
        static void handleFloat(double d);
        static void handleDouble(double d);

    public:
        static void convert(std::string const & literal);
};