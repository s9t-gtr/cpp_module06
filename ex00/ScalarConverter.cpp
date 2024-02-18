#include "ScalarConverter.hpp"

const std::string ScalarConverter::InputException::exceptionMessage() throw(){
    return "Input Error: argument is Invalid";
}

void ScalarConverter::inputCheck(const std::string input){
    bool dotFlag = false;
    size_t len = input.length();
    if(len == 1){
        char c = static_cast<char>(input[0]);
        if(!(' ' <= c && c <= '~'))
            throw InputException();
        return;
    }
    for(size_t i=0;i<len;i++){
        if((input[i] == '+' || input[i] == '-') && i == 0)
            continue;
        if(input[i] == '.'){
            if(i == 0 || dotFlag)
                throw InputException();
            dotFlag = true;
            continue;
        }
        if(input[i] == 'f' && i == len-1)
            return;
        if(!std::isdigit(input[i]))
            throw InputException();
    }
}


void ScalarConverter::convert(std::string input){
    std::string specialCase[] = {"-inff", "+inff", "-inf" ,"+inf" , "nanf", "nan"};
    std::cout << "==========" << input << "==========" << std::endl;
    std::string rChar = "";
    int rInt = 0;
    float rFloat = 0;
    double rDouble = 0;
    // bool i_over = false;
    // bool f_over = false;
    // bool d_over = false;


    if(input.length() == 1 && !std::isdigit(input[0])){
        switch(int result = std::isprint(input[0])){
            case 0:
                std::cout << "char: Non displayable" << std::endl;
            case 1:
                std::cout << "char: '"<< rChar << "'" << std::endl;
            default:
                std::cout << "int: "<< static_cast<int>(input[0]) << std::endl;
                std::cout <<std::setprecision(1)<< "float: " << static_cast<float>(input[0])<< "f" << std::endl;
                std::cout <<std::setprecision(1)<< "double: " << static_cast<double>(input[0]) << std::endl;
        }
        return;
    }

    if(input[input.length()-1] == 'f'){
        // try{
            rFloat = std::stof(input);
        // }catch(std::out_of_range&){
        //     f_over = true;
        // }
        rDouble = static_cast<double>(rFloat);
    }else{
        rDouble = std::stod(input);
        rFloat = static_cast<float>(rDouble);
    }

    /*===========================================
    ===========================================*/
    for(size_t i=0;i<specialCase->length();i++){
        if(specialCase[i] == input)
            rChar = "impossible";
    }
    if(rChar != "impossible" && std::isprint(static_cast<int>(rFloat))){
        rChar = static_cast<char>(rFloat);
        rChar = "'" + rChar + "'";
    }else{
        rChar = "Non displayable";
    }
    std::cout << "char: " << rChar << std::endl;
    /*===========================================
    ===========================================*/
    if(rChar == "impossible"){
            std::cout << "int: impossible" << std::endl;
    }else{
        try{
            rInt = std::stoi(input);
            std::cout << "int: " << rInt << std::endl;
        }catch(std::out_of_range&){
            std::cout << "int: impossible" << std::endl;
        }

    }
    if(rChar == "impossibel"){
        std::cout << "float: " << "nanika" << std::endl;
        std::cout << "double: " << "nanika" << std::endl;
    }else{
        std::cout << std::setprecision(1) << "float: " << rFloat << "f" << std::endl;
        std::cout << std::setprecision(1) << "double: " << rDouble << std::endl;
    }
    
    
}

// void toChar(const std::string str, std::stringstream ss){
//     int i;
//     ss >> i;
// }