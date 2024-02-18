#include "ScalarConverter.hpp"
#include <iomanip>
int main(){
    // if(argc == 1){

    //     return 0;
    // }
    // std::cerr << "Error: invalid arguments" << std::endl;
    // return 1;

    {
        std::string errorList[] = {"hoge", "10.a", "f", "102a.0", "a10.3", "-10.4d", "    50"};
        std::string correctList[] = {"a", "42", "42.0", "+42.0", "-42.0", "+42.0f", "-42.0f", " "};
        // char c; (void)c;
        // int i;(void)i;
        // float f;(void)f;
        // double d;(void)d;
        // const std::string str = "11.01139815254";
        try{
            for(size_t i=0;i<8;i++){
                ScalarConverter::inputCheck(correctList[i]);
                ScalarConverter::convert(correctList[i]);
            }
        }catch(ScalarConverter::InputException& e){
            std::cerr << e.exceptionMessage() << std::endl;
        }

        // ScalarConverter::convert(correctList[i]);
        // f = 1.2f * pow(10.0f, -38);
        // // d = std::stod(str);
        // std::cout << std::setprecision(38) << f << std::endl;
        // ss >> f;
        // std::cout << f << std::endl;
        // ss >> d;
        // std::cout << d << std::endl;

        // std::cout << static_cast<char>(s) << std::endl;

    }

}

/*  char
argが文字を含む時(末尾のfは許す(.が含まれていることを条件とする)): impossible
stofではddddcccのときはddddだけ取られるので弾けるようにチェックが必要


*/

/*  float

        // std::string str = "340282350000000000000000000000000000000";//float max
        // std::string str = "340282360000000000000000000000000000000";//float overflow
        // std::cout << std::stof(str) << std::endl;
 
*/