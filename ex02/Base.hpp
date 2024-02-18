#ifndef __BASE_HPP
# define __BASE_HPP

#include <iostream>

class Base{
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif