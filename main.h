#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <filesystem>
#include <yaml-cpp/yaml.h>

class Employee {
public:
    std::string name;
    std::string id;
    std::tm joining_date{};
    std::string department;

    explicit Employee(const std::string &csvLine);
};

class EmployeeBonusCalculator {
public:
    EmployeeBonusCalculator(const std::filesystem::path &csvFilePath, const std::string &yamlFilePath);

    void calculateAndPrintBonuses();

    static auto
    calculateLoyaltyBonus(const std::tm &joining_date, const std::tm &current_date,
                          const YAML::Node &bonus_ranges) -> int;

private:
    std::filesystem::path csvFilePath_;
    std::string yamlFilePath_;

};

#endif // MAIN_H