#include "Serializer.hpp"

int main() {
    Data* data = new Data(42, "Example");

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    if (data == deserializedData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data value: " << deserializedData->value << std::endl;
        std::cout << "Data name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    delete data;

    return 0;
}
