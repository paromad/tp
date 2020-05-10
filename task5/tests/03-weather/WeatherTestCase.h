
#pragma once

#include <gtest/gtest.h>
#include <string>
#include "cpr/cpr.h"

class WeatherTestCase : public ::testing::Test {
public:
    static cpr::Response GetResponse(int status_code, const std::string &text);
    static cpr::Response SimpleResponse(float temp);
};



