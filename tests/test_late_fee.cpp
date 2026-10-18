#include <gtest/gtest.h>

#include <stdexcept>

#include "late_fee.h"

TEST(LateFee, ThreeDaysAtTenCostThirty) {
    double days = 3;
    double daily = 10;

    double result = late_fee(days, daily);

    EXPECT_DOUBLE_EQ(result, 30.0);
}

TEST(LateFee, ExactlyHundredIsNotCut) {
    double days = 10;
    double daily = 10;

    double result = late_fee(days, daily);

    EXPECT_DOUBLE_EQ(result, 100.0);
}

TEST(LateFee, ZeroDaysCostNothing) {
    double days = 0;
    double daily = 10;

    double result = late_fee(days, daily);

    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(LateFee, FeeAboveHundredIsCappedAtHundred) {
    double days = 20;
    double daily = 10;

    double result = late_fee(days, daily);

    EXPECT_DOUBLE_EQ(result, 100.0);
}

TEST(LateFee, NegativeDaysAreRejected) {
    double days = -1;
    double daily = 10;

    EXPECT_THROW(late_fee(days, daily), std::invalid_argument);
}

TEST(LateFee, NegativeDailyIsRejected) {
    double days = 3;
    double daily = -10;

    EXPECT_THROW(late_fee(days, daily), std::invalid_argument);
}

TEST(LateFee, FractionalDaysAreRejected) {

    double days = 1.5;
    double daily = 10;

    EXPECT_THROW(late_fee(days, daily), std::invalid_argument);
}