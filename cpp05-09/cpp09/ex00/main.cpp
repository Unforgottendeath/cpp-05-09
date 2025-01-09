#include "utils.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./bitcoin_exchange <file>" << std::endl;
        return 1;
    }
    try
    {
        std::string file_content = read_file_content(av[1]);
        BitcoinExchange exchange(file_content);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}