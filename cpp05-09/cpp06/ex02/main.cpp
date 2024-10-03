#include "Base.hpp"
#include "utils.hpp"

int main() {
    Base* instance = generate();

    std::cout << "Identify by pointer: ";
    identify(instance);

    std::cout << "Identify by reference: ";
    identify(*instance);

    delete instance;

    return 0;
}