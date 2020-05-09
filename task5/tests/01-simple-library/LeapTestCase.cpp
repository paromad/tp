//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST(LeapTestCase, first) {
    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
}

TEST(LeapTestCase, second) {
    ASSERT_EQ(IsLeap(4), true);
}

TEST(LeapTestCase, third) {
    ASSERT_EQ(IsLeap(100), false);
}

TEST(LeapTestCase, forth) {
    ASSERT_EQ(IsLeap(400), true);
}

TEST(LeapTestCase, fifth) {
    ASSERT_EQ(IsLeap(1), false);
}