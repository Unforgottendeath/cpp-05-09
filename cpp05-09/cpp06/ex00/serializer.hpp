#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>

class Data {
public:
    int value;
    std::string name;

    Data(int v, const std::string& n) : value(v), name(n) {}
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

#endif // SERIALIZER_H
