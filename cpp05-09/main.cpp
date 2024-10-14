#include <iostream>
#include <vector>
#include <list>
#include <exception>

class NotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Element not found!";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

int main() {
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        // Test with a value not in the vector
        easyfind(vec, 10);
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int> lst = {10, 20, 30, 40, 50};
        auto it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;

        // Test with a value not in the list
        easyfind(lst, 25);
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

