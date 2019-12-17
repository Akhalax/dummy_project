#include "calculator.h"
#include <iostream>
#include <sstream>
#include "utils/utils.h"

using namespace std;

namespace {
constexpr char kEmptyString[] = "";
constexpr size_t kMinOperandsNumber = 2;
}

Calculator::Calculator() :
    mOperands()
{ }

// TODO: get rid of multiple returns
std::string Calculator::calculate(const std::string &line)
{
    clearOperands();
    stringstream ss(line);
    string item;
    //TODO: Make parsing different to skip several whitespaces. Currently 2 or more whitespaces cause error
    while (getline(ss, item, ' ')) {
        if (isNumber(item)) {
            mOperands.push(item);
        } else if (isOperator(item)) {
            if (!makeCalculation(item)) {
                return kEmptyString;
            }
        } else if (" " == item) {
            continue;
        } else {
            std::clog << "Invalid expression" << std::endl;
            return kEmptyString;
        }
    }
    string result = mOperands.empty() ? kEmptyString : mOperands.top();
    return result;
}

bool Calculator::makeCalculation(const string &_operator)
{
    if (mOperands.size() < kMinOperandsNumber) {
        std::clog << "mOperands.size() <" <<  kMinOperandsNumber << " and operator is " << _operator << std::endl;
        return false;
    }
    string firstOperandString = mOperands.top();
    mOperands.pop();
    string secondOperandString = mOperands.top();
    mOperands.pop();
    string result;

    //TODO: Make conversation and calculations not only for floats
    float first = stof(firstOperandString);
    float second = stof(secondOperandString);

    //TODO: Handle overflow
    if (_operator == "+") {
        result = sum(first, second);
    } else if (_operator == "-") {
        result = subtract(second, first);
    } else if (_operator == "*") {
        result = multiply(first, second);
    } else if (_operator == "/") {
        result = divide(second, first);
    }
    mOperands.push(result);
    return true;
}

void Calculator::clearOperands()
{
    while (!mOperands.empty()) {
        mOperands.pop();
    }
}

template<typename T1, typename T2>
string Calculator::sum(T1 a, T2 b)
{
    return to_string(a+b);
}

template<typename T1, typename T2>
string Calculator::subtract(T1 a, T2 b)
{
    return to_string(a-b);
}

template<typename T1, typename T2>
string Calculator::multiply(T1 a, T2 b)
{
    return to_string(a*b);
}

template<typename T1, typename T2>
string Calculator::divide(T1 a, T2 b)
{
    if (b == 0) {
        clog << "Devision by 0" << endl;
        return "";
    }
    return to_string(a/b);
}

