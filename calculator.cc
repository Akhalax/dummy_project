#include "calculator.h"
#include <iostream>
#include <regex>
#include <sstream>

using namespace std;

namespace {
//TODO: Get rid of regex
static const std::regex doubleRegex{ R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)" };
static const std::regex intRegex{ R"([+-]?(\d+))"};
}

Calculator::Calculator() :
    mOperands(),
    mCurrentLine()
{ }


std::string Calculator::calculate(const std::string &line)
{
    mCurrentLine = line;
    stringstream ss(line);
    string item;
    //TODO: Make parsing different to skip several whitespaces. Currently 2 or more whitespaces cause error
    while (getline(ss, item, ' ')) {
        if (isNumber(item)) {
            mOperands.push(item);
        } else if (isOperator(item)) {
            if (!makeCalculation(item)) {
                std::clog << "mOperands.size() < 2 and operator is " << item << std::endl;
                return "";
            }
        } else if (" " == item) {
            continue;
        } else {
            return "";
        }
    }
    string result = mOperands.empty() ? "" : mOperands.top();
    clearOperands();
    return result;
}

bool Calculator::makeCalculation(const string &_operator)
{
    if (mOperands.size() < 2) {
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
        result = substr(second, first);
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

bool Calculator::isOperator(const string &line)
{
    if (line == "+" || line == "-" || line == "*" || line == "/") {
        return true;
    }
    return false;
}

bool Calculator::isNumber(const string &line)
{
    //TODO: Get rid of regex
    if (std::regex_match(line, intRegex) || std::regex_match(line, doubleRegex)) {
        return true;
    }
    return false;
}

template<typename T1, typename T2>
string Calculator::sum(T1 a, T2 b)
{
    return to_string(a+b);
}

template<typename T1, typename T2>
string Calculator::substr(T1 a, T2 b)
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
        cerr << "Devision by 0" << endl;
        return "";
    }
    return to_string(a/b);
}

