#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const & literal)
{
    std::string command = literal;
    if (literal == "nan" || literal == "nanf")
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: nanf" << std::endl
                  << "double: nan" << std::endl;
    else if (literal == "-inff" || literal == "+inff" || literal == "inff")
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: " << literal << std::endl
                  << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    else
    {
        if (literal.size() == 1 && !std::isdigit(literal[0]))
        {
            handleChar(literal[0]);
            handleInt(literal[0]);
            handleFloat(literal[0]);
            handleDouble(literal[0]);
            return;
        }
        if ( literal[literal.size() - 1] == 'f')
            command = literal.substr(0, literal.size() - 1);
        std::istringstream iss(command);
        double d;
        iss >> d;
        if (iss.fail() || iss.bad() || !iss.eof())
            std::cout << "char: impossible" << std::endl
                      << "int: impossible" << std::endl
                      << "float: impossible" << std::endl
                      << "double: impossible" << std::endl;
        else
        {
            handleChar(d);
            handleInt(d);
            handleFloat(d);
            handleDouble(d);
        }
    }
}

void ScalarConverter::handleChar(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::handleInt(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::handleFloat(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "float: " << (d < 0 ? "-" : "") << "nanf" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(d);
        if (static_cast<float>(d) == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::handleDouble(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << (d < 0 ? "-" : "") << "nan" << std::endl;
    else
    {
        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
}