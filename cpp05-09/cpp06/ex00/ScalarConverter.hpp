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
        static void handleFloatSpecial(std::string const & literal);
        static void handleDoubleSpecial(std::string const & literal);
        static void handleFloat(std::string const & literal);
        static void handleInteger(std::string const & literal);
        static void handleDouble(std::string const & literal);
        static void printFloat(float value);
        static void printDouble(double value);
        static bool isPrintableChar(char c);
        template<typename T>
        static T stringToNumber(const std::string& str);

    public:
        static void convert(std::string const & literal);
};