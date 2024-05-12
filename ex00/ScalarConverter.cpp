#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input){
    // std::cout << "================= " << input << " ================="<<std::endl;
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
        // std::cout << e.what() << std::endl;
        allImpossible();
    }
}

size_t dotCount(std::string input){
    size_t dotCnt = 0;
    for (std::string::size_type i = 0; (i = input.find('.', i)) != std::string::npos; i++) {
        dotCnt++;
        if(dotCnt >= 2)
            throw std::invalid_argument("Multiple dots");
    }
    return dotCnt;
}

int ScalarConverter::getConvertType(std::string input){
    std::string::size_type len = input.length();
    if(len == 1 && !('0' <= *input.c_str() && *input.c_str() <= '9'))
        return CHAR_CASE;
    if(isNumbers(input)){
        if(input[len-1] == 'f' || input[len-1] == 'F')
            return FLOAT_CASE;
        else if(dotCount(input) == 1)
            return DOUBLE_CASE;
        return INT_CASE;
    }else{

        double d;
        std::stringstream ss(input);
        if(ss >> d)
            return DOUBLE_CASE;
        float f;
        std::string s(input.begin(), --input.end());
        ss = std::stringstream(s);
        if(ss >> f)
            return FLOAT_CASE;
        throw std::invalid_argument("invelid ");
    }
    return INT_CASE;
}


bool ScalarConverter::isNumbers(std::string input){
    std::string::size_type len = input.length();
    std::string::size_type i=0;
    size_t dotCnt = dotCount(input);
    if(input[0] == '-' || input[0] == '+')
        i++;
    for(;i<len;i++){
        if(!std::isdigit(input[i]) && input[i] != '.'){
            if((input[i] == 'f' || input[i] == 'F') && i == len - 1){
                if(dotCnt == 1)
                    return true;
                else
                    throw std::invalid_argument("invalid float literal");
            }
            else
                return false;
        }
    }
    return true;
}

void ScalarConverter::convert_char(std::string input){
    char c = *input.c_str();
    outputChar(c);
    std::cout << "int: " << static_cast<int>(c) <<std::endl;
    std::cout <<std::fixed<< std::setprecision(1) <<"float: " << static_cast<float>(c) << "f" <<std::endl;
    std::cout <<std::fixed<<std::setprecision(1)<<"double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert_int(std::string input){
    try{
        int i = stoi(input);
        outputChar(i); 
        std::cout << "int: " << i << std::endl;
        std::cout<< std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) <<"f"<< std::endl; 
        std::cout<< std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i)<< std::endl; 
    }catch(std::out_of_range&){
        allImpossible();
    }
}

void ScalarConverter::convert_float(std::string input){
    input = std::string(input.begin(), --input.end());
    float f;
    std::stringstream ss(input);
    ss >> f;
        outputChar(f);
        outputInt(static_cast<double>(f));//floatのままだとstatic_cast<float>INT_MAX(=INT_MAX+1 )との比較になってしまい都合が悪い
    // std::cout << std::fixed << std::setprecision(1) << "inf cast to int " << static_cast<int>(f) << "f"<< std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f"<< std::endl;
    if(f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity())
        std::cout<< std::fixed << std::setprecision(1) <<"double: impossible"<< std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convert_double(std::string input){
    double d;
    std::stringstream ss(input);
    ss >> d;
    outputChar(d);
    outputInt(d);
    if(d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity())
        std::cout<< std::fixed << std::setprecision(1) <<"float: impossible"<< std::endl;
    else 
        std::cout<< std::fixed << std::setprecision(1) <<"float: " << static_cast<float>(d) << "f"<< std::endl;
    std::cout<< std::fixed << std::setprecision(1)<< "double: " << d << std::endl;
}



void ScalarConverter::allImpossible(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}