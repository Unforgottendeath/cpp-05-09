#include "Data.hpp"

// Constructors
Data::Data(int v, const std::string& n) : value(v), name(n)
{
    std::cout << GREEN << "Created Data, name: " << name << ", value: " << value << RESET << std::endl;
}

Data::Data(const Data& other) : value(other.value), name(other.name)
{
    std::cout << YELLOW << "Copied Data, name: " << name << ", value: " << value << RESET << std::endl;
}

Data::Data() : value(0) , name("Default")
{
    std::cout << GREEN << "Created Data, name: " << name << ", value: " << value << RESET << std::endl;
}

// Destructor
Data::~Data()
{
    std::cout << RED << "Destroyed Data, name: " << name << ", value: " << value << RESET << std::endl;
}


// Copy Assignment Operator
Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        value = other.value;
        name = other.name;
        std::cout << YELLOW << "Assigned Data, name: " << name << ", value: " << value << RESET << std::endl;
    }
    return *this;
}
