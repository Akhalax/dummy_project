#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>


class Calculator
{
public:
    Calculator();

    std::string calculate(const std::string& line);

private:
    bool makeCalculation(const std::string& _operator);
    void clearOperands();

    template<typename T1, typename T2>
    std::string sum(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string subtract(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string multiply(T1 a, T2 b);

    template<typename T1, typename T2>
    std::string divide(T1 a, T2 b);

    std::stack <std::string> mOperands;
    std::string mCurrentLine;
};

#endif // CALCULATOR_H
