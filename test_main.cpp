#include <gtest/gtest.h>
#include "main.h"
#include "gmock/gmock.h"
#include<iomanip>
#include<ctime>

using namespace testing;

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}