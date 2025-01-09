#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#include <iostream>
#include <string>
#include <map>

class Scanner
{
public:
    Scanner(std::string source);
    Scanner(const Scanner &other);
    std::map<std::string, double> scan();

private:
    std::map<std::string, double> data;
    std::string source;
    int start;
    int current;
    int line;
};

#endif // __SCANNER_HPP__