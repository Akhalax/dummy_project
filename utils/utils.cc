#include "utils.h"
#include <regex>

namespace {
//TODO: Get rid of regex
static const std::regex doubleRegex{ R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)" };
static const std::regex intRegex{ R"([+-]?(\d+))"};
}

bool isOperator(const std::string &line)
{
    if (line == "+" || line == "-" || line == "*" || line == "/") {
        return true;
    }
    return false;
}

bool isNumber(const std::string &line)
{
    //TODO: Get rid of regex
    if (std::regex_match(line, intRegex) || std::regex_match(line, doubleRegex)) {
        return true;
    }
    return false;
}
