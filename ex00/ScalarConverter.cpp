#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input){
    std::cout << "================= " << input << " ================="<<std::endl;
    try{
        switch(int convartCase = getConvertType(input)){
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
    }catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        allImpossible();
    }
}

int ScalarConverter::getConvertType(std::string input){
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

void ScalarConverter::valueCheck(std::string input){
    std::string::size_type len = input.length();
    size_t dotCount = 0;
    if(!isSpecialString(input)){
        for (std::string::size_type i = 0; (i = input.find('.', i)) != std::string::npos; i++) {
            dotCount++;
            if(dotCount >= 2)
                throw std::invalid_argument("Multiple dots");
        }
        std::string::size_type i=0;
        if(input[0] == '-' || input[0] == '+')
            i++;
        for(;i<len-1;i++){
            if(!std::isdigit(input[i]) && input[i] != '.')
                throw std::invalid_argument("Not a number or a dot");
        }
        if(!std::isdigit(input[i]) && input[i] != 'f')
            throw std::invalid_argument("Not a number or an f at the end.");
        if(input[i] == 'f' && dotCount != 1)
            throw std::invalid_argument("invalid float literal");
    }
    
}
bool ScalarConverter::isSpecialString(std::string input){
    std::string specialString[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
    for(int i=0;i<SPECIAL_NUM;i++){
        if(input == specialString[i])
            return true;
    }
    return false;
}

template<typename T>
void ScalarConverter::outputChar(T val){
    if(0 <= val && val <= 128){
        if(std::isprint(static_cast<unsigned char>(val)))
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::convert_char(std::string input){
    char c = *input.c_str();
    outputChar(c);
    std::cout << "int: " << static_cast<int>(c) <<std::endl;
    std::cout <<std::fixed<< std::setprecision(1) <<"float: " << static_cast<float>(c) << "f" <<std::endl;
    std::cout <<std::fixed<<std::setprecision(1)<<"double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert_float(std::string input){
    try{
        double f = stod(input);
        if(f == INFINITY || f == -INFINITY)
            throw std::out_of_range("inf");
        //convert to char-------------------------------------------------
        outputChar(f);
        //convert to int-------------------------------------------------
        outputInt(f);
        //convert to float-------------------------------------------------
        if(static_cast<float>(f) == INFINITY)
            std::cout<< std::fixed << std::setprecision(1) <<"float: " << (input[0] == '-' ? "-inff": "+inff")<< std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(f) << "f"<< std::endl;

        //convert to double-------------------------------------------------
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

        outputChar(d);

        outputInt(d);
        
        if(static_cast<float>(d) == INFINITY)
            std::cout<< std::fixed << std::setprecision(1) <<"float: " << (input[0] == '-' ? "-inff": "+inff")<< std::endl;
        else
            std::cout<< std::fixed << std::setprecision(1) <<"float: " << static_cast<float>(d) << "f"<< std::endl;

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
        std::cout << "int" << std::endl;
        int i = stoi(input);
        outputChar(i); 
        std::cout << "int: " << i << std::endl;
        std::cout<< std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) <<"f"<< std::endl; 
        std::cout<< std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i)<< std::endl; 
    }catch(std::out_of_range&){
        allImpossible();
    }
}

void ScalarConverter::allImpossible(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}