#ifndef __SERIALIZER_HPP
# define __SERIALIZER_HPP

#include "Data.hpp"

class Serializer{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif