#include "Base.hpp"

int main(){
    std::cout << "============= pointer =============" << std::endl;
    std::cout << "===================================" << std::endl;
    std::srand(std::time(NULL));
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        try{
            Base *p = generate();
            identify(p);
            delete p;
        }catch(std::bad_alloc&){
            std::cerr << "Error: generate(): new failed" << std::endl;
        }
    }

    std::cout << "============ reference ============" << std::endl;
    std::cout << "===================================" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << "------------------------------" << std::endl;
        try{
            Base *r = generate();
            identify(*r);
            delete r;
        }catch(std::bad_alloc&){
            std::cerr << "Error: generate(): new failed" << std::endl;
        }
    }
}