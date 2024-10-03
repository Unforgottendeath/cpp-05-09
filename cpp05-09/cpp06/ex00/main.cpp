#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("'a'");  
    ScalarConverter::convert("42");     
    ScalarConverter::convert("3.14f"); 
    ScalarConverter::convert("-4.2");   
    ScalarConverter::convert("nanf");    
    ScalarConverter::convert("+inf");    
    return 0;
}