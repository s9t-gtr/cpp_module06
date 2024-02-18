#include "Serializer.hpp"

int main(){
    Data data;
    uintptr_t p;

    std::cout << "data: " << &data << std::endl;

    p = Serializer::serialize(&data);
    std::cout << "p: " << p << std::endl;

    Data *other = Serializer::deserialize(p);
    std::cout << "other: " << other << std::endl;
}