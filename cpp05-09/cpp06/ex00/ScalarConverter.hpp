#pragma once

#include <string>
#include <iostream>
#include <exception>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

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

    public:
        static void convert(std::string const & literal);
};