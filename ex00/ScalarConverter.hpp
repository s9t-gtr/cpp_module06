#ifndef __SCALARCONVERTER_HPP
# define __SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
class ScalarConverter{
    public:
        static void convert(const std::string input);
    private:
        static int getConvertCase(std::string input);
        static void valueCheck(std::string input);
        static bool isSpecialString(std::string input);
        static void convert_char(std::string input);
        static void convert_float(std::string input);
        static void convert_double(std::string input);
        static void convert_int(std::string input);

    public:
        class InputException: public std::exception{
            public:
                void allImpossible() throw();
        };
};

#endif