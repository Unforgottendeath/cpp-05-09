#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
        return 1;
    }
    std::ostringstream oss;
    oss << av[1];
    ScalarConverter::convert(oss.str());
    return 0;
}