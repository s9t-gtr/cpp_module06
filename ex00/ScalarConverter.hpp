#ifndef __SCALARCONVERTER_HPP
# define __SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <bitset>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string input);
    private:
        template<typename T>
        static void outputChar(T val);
        template<typename T>
        static void outputInt(T val);
        static int getConvertType(std::string input);
        static void valueCheck(std::string input);
        static bool isSpecialString(std::string input);

        static void convert_char(std::string input);
        static void convert_float(std::string input);
        static void convert_double(std::string input);
        static void convert_int(std::string input);

        static void allImpossible();
    public:
        const static int CHAR_CASE = 1;
        const static int FLOAT_CASE = 2;
        const static int DOUBLE_CASE = 3;
        const static int INT_CASE = 4;
        const static int SPECIAL_NUM = 6;
};

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


template<typename T>
void ScalarConverter::outputInt(T val){
    if(INT_MIN <= val && val <= INT_MAX){
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }else
        std::cout << "int: impossible" << std::endl;

}


#endif