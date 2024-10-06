#pragma once

#include <iostream>
#include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";
const std::string ORANGE = "\033[38;5;208m";

class Data
{
public:
    int value;
    std::string name;

    // Constructors
    Data(int v, const std::string& n);
    Data(const Data& other);
    Data();

    // Destructor
    ~Data();

    // Operator overload
    Data& operator=(const Data& other);
};