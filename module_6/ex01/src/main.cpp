#include "Data.hpp"       // Your Data struct header
#include "Serializer.hpp" // Your Serializer class header
#include <iostream>

int main() {
    Data my_data;
    my_data.first_name = "John";
    my_data.last_name = "Doe";
    my_data.age = 42;

    Data *original_ptr = &my_data;

    std::cout << "Original pointer address:\t" << original_ptr << std::endl;
    std::cout << "Original data:\t\t\t" << original_ptr->first_name << " "
              << original_ptr->last_name << ", age " << original_ptr->age
              << std::endl;

    uintptr_t raw = Serializer::serialize(original_ptr);

    Data *deserialized_ptr = Serializer::deserialize(raw);

    std::cout << "\n--- After Serialization & Deserialization ---\n"
              << std::endl;
    std::cout << "Deserialized pointer address:\t" << deserialized_ptr
              << std::endl;

    if (original_ptr == deserialized_ptr) {
        std::cout << "Data via new pointer:\t\t"
                  << deserialized_ptr->first_name << " "
                  << deserialized_ptr->last_name << ", age "
                  << deserialized_ptr->age << std::endl;
        std::cout << "✅ Success: Pointers are identical." << std::endl;
    } else {
        std::cout << "❌ Failure: Pointers do not match." << std::endl;
    }

    return 0;
}
