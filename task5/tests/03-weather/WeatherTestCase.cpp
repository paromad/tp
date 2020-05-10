//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"
#include "json.hpp"

using json = nlohmann::json;

cpr::Response WeatherTestCase::GetResponse(int status_code, const std::string &text) {
    cpr::Response res;
    res.status_code = status_code;
    res.text = text;
    return res;
}

cpr::Response WeatherTestCase::SimpleResponse(float temp) {
    std::string text = "{\"list\":[{\"main\":{\"temp\": " + std::to_string(temp) + "}}]}";
    return WeatherTestCase::GetResponse(200, text);
}

TEST_F(WeatherTestCase, key) {
    WeatherMock a;
    a.SetApiKey("key");
}

TEST_F(WeatherTestCase, exception) {
    WeatherMock a;
    EXPECT_CALL(a, Get("city"))
        .Times(1)
        .WillOnce(::testing::Return(WeatherTestCase::GetResponse(201, "")));
    ASSERT_THROW(a.GetResponseForCity("city"), std::invalid_argument);
}

TEST_F(WeatherTestCase, difference) {
    WeatherMock a;
    EXPECT_CALL(a, Get(::testing::_))
        .Times(4)
        .WillOnce(::testing::Return(WeatherTestCase::SimpleResponse(100)))
        .WillOnce(::testing::Return(WeatherTestCase::SimpleResponse(101)))
        .WillOnce(::testing::Return(WeatherTestCase::SimpleResponse(101)))
        .WillOnce(::testing::Return(WeatherTestCase::SimpleResponse(100)));
    std::string res = a.GetDifferenceString("first", "second");
    std::string result = a.GetDifferenceString("first", "second");
    ASSERT_EQ(res, std::string("Weather in first is colder than in second by 1 degrees"));
    ASSERT_EQ(result, std::string("Weather in first is warmer than in second by 1 degrees"));
}
