#include "Base.hpp"

int main(){
    std::cout << "============= pointer =============" << std::endl;
    std::cout << "===================================" << std::endl;
    Base *p = 0;
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        try{
            Base *p = generate();
        }catch(std::bad_alloc&){
            std::cerr << "Error: generate(): new failed" << std::endl;
        }
        identify(p);
        delete p;
    }

    std::cout << "============ reference ============" << std::endl;
    std::cout << "===================================" << std::endl;
    Base *r = 0;
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        try{
            r = generate();
        }catch(std::bad_alloc&){
            std::cerr << "Error: generate(): new failed" << std::endl;
        }
        Base *r = generate();
        identify(*r);
        delete r;
    }
}