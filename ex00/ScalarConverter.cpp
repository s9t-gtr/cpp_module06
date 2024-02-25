#include "ScalarConverter.hpp"

void ScalarConverter::InputException::allImpossible() throw(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

#define SPECIAL_NUM 6
bool ScalarConverter::isSpecialString(std::string input){
    std::string specialString[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
    for(int i=0;i<SPECIAL_NUM;i++){
        if(input == specialString[i])
            return true;
    }
    return false;
}

void ScalarConverter::valueCheck(std::string input){
    std::string::size_type len = input.length();
    size_t count = 0;
    if(!isSpecialString(input)){
        for (std::string::size_type i = 0; (i = input.find('.', i)) != std::string::npos; i++) {
            count++;
            if(count >= 2)
                throw InputException();
        }
        std::string::size_type i=0;
        if(input[0] == '-' || input[0] == '+')
            i++;
        for(;i<len-1;i++){
            if(!std::isdigit(input[i]) && input[i] != '.')
                throw InputException();
        }
    }
    
}


#define CHAR_CASE 1
#define FLOAT_CASE 2
#define DOUBLE_CASE 3
#define INT_CASE 4
int ScalarConverter::getConvertCase(std::string input){

    std::string::size_type len = input.length();
    if(len == 1 && !('0' <= *input.c_str() && *input.c_str() <= '9'))
        return CHAR_CASE;
    valueCheck(input);
    if(input != "+inf" && input != "-inf" && input[len - 1] == 'f')
        return FLOAT_CASE;
    if(input == "+inf" || input == "-inf" || input == "nan" || input.find(".") != std::string::npos || (std::stod(input) > INT_MAX || std::stod(input) < INT_MIN))
        return DOUBLE_CASE;
    return INT_CASE;
}

void ScalarConverter::convert_char(std::string input){
    char c = *input.c_str();
    std::cout << "char: " << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) <<std::endl;
    std::cout <<std::fixed<< std::setprecision(1) <<"float: " << static_cast<float>(c) << "f" <<std::endl;
    std::cout <<std::fixed<<std::setprecision(1)<<"double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert_float(std::string input){
    try{
        double f = stod(input);
        if(f == INFINITY || f == -INFINITY)
            throw std::out_of_range("inf");
        if(0 <= f && f <= 128){
            if(' ' <= f && f <= '~')
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }else
            std::cout << "char: impossible" << std::endl;



        if(INT_MIN <= f && f <= INT_MAX){
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        }else
            std::cout << "int: impossible" << std::endl;
            



        if(std::floor(f) == f){
            if(static_cast<float>(f) == INFINITY)
                std::cout << "float: +inff" << std::endl;
            else if(static_cast<float>(f) == -INFINITY)
                std::cout << "float: -inff" << std::endl;
            else
                std::cout << std::fixed << std::setprecision(1)<< "float: " << static_cast<float>(f) << "f"<< std::endl;
        }
        else
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(f) << "f"<< std::endl;
        if(std::floor(f) == f)
            std::cout<< std::fixed << std::setprecision(1) << "double: " << (f)  << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << "double: " << (f) << std::endl;

    }catch(std::out_of_range&){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (input[0] == '-' ? "-inff": "+inff") << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    
}
void ScalarConverter::convert_double(std::string input){
    try{
        double d = stod(input);
        if(d == INFINITY || d == -INFINITY)
            throw std::out_of_range("inf");
        if(0 <= d && d <= 128){
            if(' ' <= d && d <= '~')
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }else
            std::cout << "char: impossible" << std::endl;

        if(INT_MIN <= d && d <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        
        if(std::floor(static_cast<float>(d)) == static_cast<float>(d))
            if(static_cast<float>(d) == INFINITY)
                std::cout<< std::fixed << std::setprecision(1) <<"float: " << (input[0] == '-' ? "-inff": "+inff")<< std::endl;
            else
                std::cout<< std::fixed << std::setprecision(1) <<"float: " << static_cast<float>(d) << "f"<< std::endl;
        else
            std::cout<< std::fixed << std::setprecision(1)  <<"float: " << static_cast<float>(d) << "f" << std::endl;
        if(std::floor(d) == d)
            std::cout << "double: " << d << std::endl;
        else
            std::cout<< std::fixed << std::setprecision(1)<< "double: " << d << std::endl;
    }catch(std::out_of_range&){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (input[0] == '-' ? "-inff": "+inff") << std::endl;
        std::cout << "double: " << (input[0] == '-' ? "-inf": "+inf") << std::endl;
    }
}
void ScalarConverter::convert_int(std::string input){
    try{
        int i = stoi(input);
        if(0 <= i && i <= 128){
            if(' ' <= i && i <= '~')
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }else
            std::cout << "char: impossible" << std::endl;
        
       std::cout << "int: " << i << std::endl; 
       std::cout<< std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) <<"f"<< std::endl; 
       std::cout<< std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i)<< std::endl; 
    }catch(std::out_of_range&){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl; 
    }
}
void ScalarConverter::convert(std::string input){
    std::cout << "================= " << input << " ================="<<std::endl;
    try{
        switch(int convartCase = getConvertCase(input)){
            case CHAR_CASE:
                convert_char(input);
                break;
            case FLOAT_CASE:
                convert_float(input);
                break;
            case DOUBLE_CASE:
                convert_double(input);
                break;
            case INT_CASE:
                convert_int(input);
                break;
        }
    }catch(InputException& e){
        e.allImpossible();
    }
}
