#ifndef __SERIALIZER_HPP
# define __SERIALIZER_HPP

#include <iostream>

class Data;

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
    public:
        virtual ~Serializer() = 0;

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif