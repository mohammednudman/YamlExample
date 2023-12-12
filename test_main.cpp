#include <gtest/gtest.h>
#include "employee_bonus.h"

using namespace employee;

TEST(EmployeeTest, ConstructorTest) {
    std::string csvLine = "John Doe,123,2022-01-01,HR";
    employee::Employee employee(csvLine);

    ASSERT_EQ("John Doe", employee.name);
    ASSERT_EQ("123", employee.id);
}

TEST(EmployeeBonusCalculatorTest, LoyaltyBonusTest) {
    std::tm joiningDate = {};  // Set the joining date
    std::tm currentDate = {}; // Set the current date

// Create an instance of EmployeeBonusCalculator
    EmployeeBonusCalculator calculator({}, {});

// Call the static function for loyalty bonus calculation
    int bonus = EmployeeBonusCalculator::calculateLoyaltyBonus(joiningDate, currentDate, YAML::Load("{}"));

// Add assertions based on your expectations
    ASSERT_EQ(0, bonus); // Adjust based on your expectations
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}