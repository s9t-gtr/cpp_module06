#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p){
        A *a = dynamic_cast<A*>(p);
        if(a != NULL){
            std::cout << "The actual type of the object pointed to by p is A" << std::endl;
            return;
        }
    

        B *b = dynamic_cast<B*>(p);
        if(b != NULL){
            std::cout << "The actual type of the object pointed to by p is B" << std::endl;
            return;
        }

        C *c = dynamic_cast<C*>(p);
        if(c != NULL){
            std::cout << "The actual type of the object pointed to by p is C" << std::endl;
            return;
        }
}

void identify(Base& p){
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "The actual type of the object pointed to by p is A" << std::endl;
    }catch(std::bad_cast&){}

    try{
        B b = dynamic_cast<B&>(p);
        std::cout << "The actual type of the object pointed to by p is B" << std::endl;
    }catch(std::bad_cast&){}

    try{
        C c = dynamic_cast<C&>(p);
        std::cout << "The actual type of the object pointed to by p is C" << std::endl;
    }catch(std::bad_cast&){}
}