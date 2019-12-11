#include "project.h"
#include <string>
#include <iostream>
#include "calculator.h"

int main() {
  Calculator calc;
  std::string expression;
  std::getline(std::cin, expression);

  std::string result = calc.calculate(expression);
  //TODO: Don't print out result if the expression was invalid
  std::cout << "result = " << result << std::endl;

  return 0;
}
