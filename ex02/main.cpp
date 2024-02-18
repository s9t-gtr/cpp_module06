#include "Base.hpp"

int main(){
    std::cout << "============= pointer =============" << std::endl;
    std::cout << "===================================" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        Base *p = generate();
        identify(p);
        delete p;
    }

    std::cout << "============ reference ============" << std::endl;
    std::cout << "===================================" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        Base *r = generate();
        identify(*r);
        delete r;
    }
}