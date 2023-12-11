#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <yaml-cpp/yaml.h>

Employee::Employee(const std::string &csvLine) {
    std::istringstream iss(csvLine);
    std::string joining_date_str;

    if (!(getline(iss, name, ',') &&
          getline(iss, id, ',') &&
          getline(iss, joining_date_str, ',') &&
          getline(iss, department, ','))) {
        throw std::runtime_error("Error: Failed to read employee data from CSV.");
    }

    std::istringstream date_stream(joining_date_str);
    date_stream >> std::get_time(&joining_date, "%Y-%m-%d");

    if (date_stream.fail())
        throw std::runtime_error("Error: Failed to convert joining date.");
}

EmployeeBonusCalculator::EmployeeBonusCalculator(const std::filesystem::path &csvFilePath,
                                                 const std::string &yamlFilePath)
        : csvFilePath_(csvFilePath), yamlFilePath_(yamlFilePath) {}

void EmployeeBonusCalculator::calculateAndPrintBonuses() {
    std::ifstream csv_file(csvFilePath_);

    if (!csv_file.is_open()) {
        std::cerr << "Error: Unable to open CSV file." << '\n';
        return;
    }

    std::vector<Employee> employee_data;
    std::string line;

    getline(csv_file, line);  // Skip header line

    while (getline(csv_file, line)) {
        try {
            employee_data.emplace_back(line); // Use the Employee constructor
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
            continue; // Skip this line and move to the next one
        }
    }

    YAML::Node bonus_range_config = YAML::LoadFile(yamlFilePath_)["RangeAmountConfig"];

    std::time_t current_time = std::time(nullptr);
    std::tm *current_date = std::localtime(&current_time);

    for (const auto &employee: employee_data) {
        int bonus = calculateLoyaltyBonus(employee.joining_date, *current_date, bonus_range_config);
        std::cout << employee.name << " (ID: " << employee.id << "): Loyalty Bonus - " << bonus << '\n';
    }
}

auto EmployeeBonusCalculator::calculateLoyaltyBonus(const std::tm &joining_date, const std::tm &current_date,
                                                    const YAML::Node &bonus_ranges) -> int {
    int years_worked = current_date.tm_year - joining_date.tm_year;

    int bonus = 0;
    for (const auto &range: bonus_ranges) {
        int range_limit = std::stoi(range.first.as<std::string>());
        int bonus_amount = range.second.as<int>();

        if (years_worked <= range_limit) {
            bonus = bonus_amount;
            break;
        }
    }

    return bonus;
}

int main() {
    std::filesystem::path csvFilePath = R"(C:\Users\Mohammed\CLionProjects\untitled\Employee.csv)";
    std::string yamlFilePath = R"(C:\Users\Mohammed\CLionProjects\untitled\BonusRange.yaml)";

    EmployeeBonusCalculator calculator(csvFilePath, yamlFilePath);
    calculator.calculateAndPrintBonuses();

    return 0;
}
