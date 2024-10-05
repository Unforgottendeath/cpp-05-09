#include "Whatever.hpp"

int main() {
    {
        // Test swap function
        int x = 5, y = 10;
        std::cout << RED << "Before swap: x = " << x << ", y = " << y << RESET << std::endl;
        swap(x, y);
        std::cout << GREEN << "After swap: x = " << x << ", y = " << y << RESET << std::endl;

        // Test min function
        double a = 3.14, b = 2.71;
        std::cout << YELLOW << "Min between " << a << " and " << b << " is: " << Min(a, b) << RESET << std::endl;

        // Test max function
        std::string str1 = "apple", str2 = "banana";
        std::cout << ORANGE << "Max between \"" << str1 << "\" and \"" << str2 << "\" is: \"" << Max(str1, str2) << "\"" << RESET << std::endl;
    }
    std::cout << YELLOW << "<---------------------------------------------------------------------------------------------------------------------------->" << RESET << std::endl;
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return 0;
}
