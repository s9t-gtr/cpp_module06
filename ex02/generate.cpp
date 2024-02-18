#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void){
    Base *p = 0;
    char type = 'N';
    switch(int index = (std::rand() % 3) + 1){
        case 1:
            p = new A();
            type = 'A';
            break;
        case 2:
            p = new B();
            type = 'B';
            break;
        case 3:
            p = new C();
            type = 'C';
            break;
        default:
            std::cerr << "generate(): index is Invalid" << std::endl;
    }
    std::cout << "generate(): " << type << " created" << std::endl;
    return p;
}