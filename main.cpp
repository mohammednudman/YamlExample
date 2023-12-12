#include <string>
#include "employee_bonus.h"

using namespace employee;

int main() {
    std::string csvFilePath = R"(C:\Users\Mohammed\CLionProjects\untitled\Employee.csv)";
    std::string yamlFilePath = R"(C:\Users\Mohammed\CLionProjects\untitled\BonusRange.yaml)";

    EmployeeBonusCalculator calculator(csvFilePath, yamlFilePath);
    calculator.calculateAndPrintBonuses();

    return 0;
}