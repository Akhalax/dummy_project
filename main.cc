#include "project.h"
#include <string>
#include <iostream>
#include "calculator.h"

int main() {
  Calculator calc;
  std::string expression;
  std::getline(std::cin, expression);

  std::string result = calc.calculate(expression);
  std::cout << "result = " << result << std::endl;

  return 0;
}
