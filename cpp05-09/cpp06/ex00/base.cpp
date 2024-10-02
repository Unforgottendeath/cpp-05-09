#include "Base.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    int random = rand() % 3; // Generate a random number between 0 and 2

    if (random == 0) return new A();
    else if (random == 1) return new B();
    else return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}
