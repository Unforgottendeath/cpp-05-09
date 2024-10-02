#include <iostream>
#include "Serializer.h"

int main() {
    // Create a Data object
    Data* data = new Data(42, "Example");

    // Serialize the Data pointer
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized pointer: " << raw << std::endl;

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Check if the original pointer and the deserialized pointer are the same
    if (data == deserializedData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data value: " << deserializedData->value << std::endl;
        std::cout << "Data name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    // Clean up
    delete data;

    return 0;
}
