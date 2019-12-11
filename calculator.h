#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>


class Calculator
{
public:
    Calculator();

    template<typename T1, typename T2>
    std::string sum(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string substr(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string multiply(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string divide(T1 a, T2 b);

    std::string calculate(const std::string& line);

private:
    bool makeCalculation(const std::string& _operator);
    void clearOperands();

    bool isOperator(const std::string& line);
    bool isNumber(const std::string& line);
    std::stack <std::string> mOperands;
    std::string mCurrentLine;
};

#endif // CALCULATOR_H
