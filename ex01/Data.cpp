#include "Data.hpp"

Data::Data(): name("TARO"){
    std::cout << "Data: Default constructor called" << std::endl;
}

Data::~Data(){
    std::cout << "Data: Destructor called" << std::endl;
}

Data::Data(const Data& other){
    std::cout << "Data: Copy constructor called" << std::endl;
    *this = other;
}

Data& Data::operator=(const Data& other){
    if(this == &other)
        return *this;
    const_cast<std::string&>(name) = other.name;
    return *this;
}