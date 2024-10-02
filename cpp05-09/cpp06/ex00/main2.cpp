#include "Base.h"

int main() {
    // Generate a random instance of A, B, or C
    Base* instance = generate();

    // Identify the type using the pointer version
    std::cout << "Identify by pointer: ";
    identify(instance);

    // Identify the type using the reference version
    std::cout << "Identify by reference: ";
    identify(*instance);

    // Clean up
    delete instance;

    return 0;
}
