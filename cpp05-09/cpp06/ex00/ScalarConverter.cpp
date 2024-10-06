#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) 
{
    try {
        if (literal.length() == 1 && isPrintableChar(literal[0])) {
            char c = literal[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
        } else if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
            handleFloatSpecial(literal);
        } else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
            handleDoubleSpecial(literal);
        } else if (literal.back() == 'f') {
            handleFloat(literal);
        } else {
            handleInteger(literal);
            handleDouble(literal);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ScalarConverter::handleFloatSpecial(const std::string& literal)
{
    float value = (literal == "nanf") ? std::numeric_limits<float>::quiet_NaN() :
                    (literal == "-inff") ? -std::numeric_limits<float>::infinity() :
                    std::numeric_limits<float>::infinity();
    printFloat(value);
}

void ScalarConverter::handleDoubleSpecial(const std::string& literal)
{
    double value = (literal == "nan") ? std::numeric_limits<double>::quiet_NaN() :
                    (literal == "-inf") ? -std::numeric_limits<double>::infinity() :
                    std::numeric_limits<double>::infinity();
    printDouble(value);
}

void ScalarConverter::handleFloat(const std::string& literal)
{
    std::string number = literal.substr(0, literal.length() - 1); 
    float value = std::stof(number);
    printFloat(value);
}

void ScalarConverter::handleInteger(const std::string& literal)
{
    int value = std::stoi(literal);
    std::cout << "int: " << value << std::endl;
}

void ScalarConverter::handleDouble(const std::string& literal)
{
    double value = std::stod(literal);
    printDouble(value);
}

void ScalarConverter::printFloat(float value)
    {
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value << std::endl;
}

bool ScalarConverter::isPrintableChar(char c) 
{
    return c >= 32 && c <= 126;
}