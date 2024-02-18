#ifndef __DATA_HPP
# define __DATA_HPP

#include <iostream>

class Data{
    public:
        Data();
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
    private:
        const std::string name;
};

#endif