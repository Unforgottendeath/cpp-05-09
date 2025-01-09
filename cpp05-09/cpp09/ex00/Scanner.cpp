#include "Scanner.hpp"

Scanner::Scanner(std::string source) : source(source)
{
}

Scanner::Scanner(const Scanner &other) : data(other.data), source(other.source)
{
}

// std::map<std::string, double> Scanner::scan()
// {
//     // while !is_at_end()
//     // {
//     //     start = current;
//     //     scan_token();
//     }
// }