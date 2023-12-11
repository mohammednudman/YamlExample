#include <gtest/gtest.h>
#include "../main.h"

// Test the Employee class
TEST(EmployeeTest, Constructor) {
    std::string csvLine = "John Doe,123,2022-01-01,Engineering";
    Employee employee(csvLine);

    EXPECT_EQ(employee.name, "John Doe");
    EXPECT_EQ(employee.id, "123");
    EXPECT_EQ(employee.joining_date.tm_year, 122); // 2022 - 1900
    EXPECT_EQ(employee.department, "Engineering");
}

// Test the EmployeeBonusCalculator class
TEST(EmployeeBonusCalculatorTest, CalculateLoyaltyBonus) {
    std::filesystem::path csvFilePath = "C:\\Users\\Mohammed\\CLionProjects\\untitled\\Employee.csv";
    std::string yamlFilePath = "C:\\Users\\Mohammed\\CLionProjects\\untitled\\BonusRange.yaml";

    YAML::Node bonus_range_config = YAML::LoadFile(yamlFilePath)["RangeAmountConfig"];

    EmployeeBonusCalculator calculator(csvFilePath, yamlFilePath);

    // Use current date and a date one year ago for testing
    std::time_t current_time = std::time(nullptr);
    std::tm *current_date = std::localtime(&current_time);
    std::tm one_year_ago = *current_date;
    one_year_ago.tm_year -= 1;

    int bonus = EmployeeBonusCalculator::calculateLoyaltyBonus(one_year_ago, *current_date, bonus_range_config);

    EXPECT_EQ(bonus, 50000); // Bonus for 1 year of work
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
