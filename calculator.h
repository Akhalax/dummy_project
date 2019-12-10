#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>


class Calculator
{
public:
    Calculator();

    template<typename T, typename T1, typename T2>
    T sum(T1 a, T2 b);

    template<typename T, typename T1, typename T2>
    T substr(T1 a, T2 b);

    template<typename T, typename T1, typename T2>
    T multiply(T1 a, T2 b);

    template<typename T, typename T1, typename T2>
    T divide(T1 a, T2 b);

    std::string calculate(const std::string& line);

    bool isValid(const std::string& line);

private:
    bool isOperator(const std::string& line);
    bool isNumber(const std::string& line);
    std::stack <std::string> mOperands;
    std::string mCurrentLine;
};

#endif // CALCULATOR_H
