#include "calculator.h"
#include <iostream>
#include <regex>

using namespace std;

namespace {
static const std::regex doubleRegex{ R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)" };
static const std::regex intRegex{ R"([+-]?(\d+))"};
static const std::regex validRegex{ R"([+-]?(\d+))([+-*/])"};
}

Calculator::Calculator() :
    mOperands(),
    mCurrentLine()
{ }


std::string Calculator::calculate(const std::string &line)
{
    mCurrentLine = line;


}

// Not working at the moment
bool Calculator::isValid(const string &line)
{
//    if (std::regex_match(line, validRegex)){
//        return true;
//    }
    return false;
}

bool Calculator::isOperator(const string &line)
{
    if (line == "+" || line == "-" || line == "*" || line == "/") {
        return true;
    }
    return false;
}

template<typename T, typename T1, typename T2>
T Calculator::sum(T1 a, T2 b)
{

}

template<typename T, typename T1, typename T2>
T Calculator::substr(T1 a, T2 b)
{

}

template<typename T, typename T1, typename T2>
T Calculator::multiply(T1 a, T2 b)
{

}

template<typename T, typename T1, typename T2>
T Calculator::divide(T1 a, T2 b)
{

}


void handleDouble(double d) {
    std::cout << "Double = " << d << "\n";
}

void handleInt(int i) {
    std::cout << "Int = " << i << "\n";
}

void handleString(std::string const & s) {
    std::cout << "String = " << s << "\n";
}

void parse(std::string const& input) {

    if (std::regex_match(input, intRegex)){
        istringstream inputStream(input);
        int i;
        inputStream >> i;
        handleInt(i);
    }
    else if (std::regex_match(input, doubleRegex)) {
        istringstream inputStream(input);
        double d;
        inputStream >> d;
        handleDouble(d);
    }
    else {
        handleString(input);
    }
}

//int main()
//{
//    Calculator calc;
//    parse("+4.234e10");
//    parse("1 2");
//    parse("1.0");
//    parse("345.0");
//    parse("-15");
//    parse("123abc");
//    cout << "Float " << 52.0001 << endl;
//    cout << "is valid" << "2 3 +" << calc.isValid("2 3 +") << endl;
//}
