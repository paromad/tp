//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, Testic) {
    ASSERT_EQ(3, Add(1, 2));
}