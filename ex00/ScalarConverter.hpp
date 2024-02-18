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
        static void inputCheck(const std::string input);
    
        // static char rChar;
        // static int rInt;
        // static float rFloat;
        // static double rDouble;

    public:
        class InputException: public std::exception{
            public:
                InputException(){};
                virtual const std::string exceptionMessage() throw();
        };
};

#endif