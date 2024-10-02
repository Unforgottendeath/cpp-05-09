#pragma once

#include <cstdint>
#include "Data.hpp" // Make sure to include the Data class

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
