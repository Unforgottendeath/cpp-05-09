#include "easyfind.hpp"

int main() {
    try {
        const int array[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(array, array + 5 );
        std::vector<int>::iterator  it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        easyfind(vec, 10);
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        const int array[] = {10, 20, 30, 40, 50};
        std::list<int> lst(array, array + 5);
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;

        easyfind(lst, 25);
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}