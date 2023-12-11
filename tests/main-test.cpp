// test_main.cpp
#include "gtest/gtest.h"
#include "../main.h"

// Define test fixtures if needed

TEST(EmployeeTest, ConstructorTest) {
    // Add your test cases for the Employee class constructor
    // Example:
    std::string csvLine = "John Doe,123,2022-01-01,HR";
    Employee employee(csvLine);

    EXPECT_EQ(employee.name, "John Doe");
    EXPECT_EQ(employee.id, "123");
    // Add more assertions as needed
}

TEST(BonusCalculatorTest, LoyaltyBonusCalculationTest) {
    // Add your test cases for the EmployeeBonusCalculator::calculateLoyaltyBonus method
    // Example:
    std::tm joining_date = {};
    joining_date.tm_year = 2020 - 1900; // Year is 2020
    std::tm current_date = {};
    current_date.tm_year = 2023 - 1900; // Year is 2023

    YAML::Node bonus_ranges;
    bonus_ranges["1"] = 100;
    bonus_ranges["2"] = 200;

    int bonus = EmployeeBonusCalculator::calculateLoyaltyBonus(joining_date, current_date, bonus_ranges);

    EXPECT_EQ(bonus, 100); // Adjust the expected value based on your calculation
    // Add more assertions as needed
}

// You can add more test cases as needed

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
