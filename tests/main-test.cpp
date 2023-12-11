#include <gtest/gtest.h>
#include "../main.h"

// Test the Employee class
TEST(EmployeeTest, Constructor) {
std::string csvLine = "John Doe,123,2022-01-01,Engineering";
Employee employee(csvLine);

EXPECT_EQ(employee.name, "John Doe");
EXPECT_EQ(employee.id, "123");

// Assuming you have set the joining_date_str correctly in the test data
EXPECT_EQ(employee.joining_date.tm_year, 122); // 2022 - 1900
EXPECT_EQ(employee.department, "Engineering");
}

// Test the EmployeeBonusCalculator class
TEST(EmployeeBonusCalculatorTest, CalculateLoyaltyBonus) {
std::filesystem::path csvFilePath = "C:\\Users\\Mohammed\\CLionProjects\\untitled\\Employee.csv";
std::string yamlFilePath = "C:\\Users\\Mohammed\\CLionProjects\\untitled\\BonusRange.yaml";

// Create a sample bonus range configuration for testing
YAML::Node bonus_range_config;
bonus_range_config["RangeAmountConfig"]["1"] = 100;
bonus_range_config["RangeAmountConfig"]["3"] = 200;
bonus_range_config["RangeAmountConfig"]["5"] = 300;

EmployeeBonusCalculator calculator(csvFilePath, yamlFilePath);

// Assuming you have a valid calculateLoyaltyBonus implementation
int bonus = EmployeeBonusCalculator::calculateLoyaltyBonus({2022, 0, 1, 0, 0, 0}, {2023, 0, 1, 0, 0, 0}, bonus_range_config);

EXPECT_EQ(bonus, 100); // Bonus for 1 year of work
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
