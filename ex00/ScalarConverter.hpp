#ifndef __SCALARCONVERTER_HPP
# define __SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>


class ScalarConverter{
    private:
        ScalarConverter();
    public:
        static void convert(const std::string input);
    private:
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

#endif