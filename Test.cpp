/* Add more test cases here */
/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "iostream"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));

    CHECK(snowman(33232124) == string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));

    CHECK(snowman(12222212) == string(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));

    CHECK(snowman(32443333) == string("   _\n  /_\\\n (-.-)\n/(> <)\\\n (___)"));

    CHECK(snowman(44444432) == string(" ___\n(_*_)\n(- -)\n(> <)\n(\" \")"));

    CHECK(snowman(41341144) == string("  ___\n (_*_)\n (O,-)\n<(   )>\n (   )"));

    CHECK(snowman(11111111) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));

    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));

    CHECK(snowman(12344321) == string("_===_\n(O.-)\n(] [)\\\n( : )"));

    CHECK(snowman(23232223) == string("  ___\n .....\n\\(o_O)/\n (] [)\n (___)"));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS_AS(snowman(555), logic_error);
    CHECK_THROWS_AS(snowman(11114511), invalid_argument);

    CHECK_THROWS(snowman(2224));
    CHECK_THROWS_AS(snowman(2224), logic_error);
    CHECK_THROWS_AS(snowman(11110011), invalid_argument);

    CHECK_THROWS(snowman(5551234));
    CHECK_THROWS_AS(snowman(5551234), logic_error);
    CHECK_THROWS_AS(snowman(11114011), invalid_argument);

    CHECK_THROWS(snowman(123451234));
    CHECK_THROWS_AS(snowman(123451234), logic_error);
    CHECK_THROWS_AS(snowman(11114000), invalid_argument);

    // check minus values
    CHECK_THROWS(snowman(-1232));
    CHECK_THROWS_AS(snowman(-1232), logic_error);
    CHECK_THROWS_AS(snowman(-12341234), logic_error);
    /* Add more checks here */

    //
    CHECK_THROWS(snowman(-9999));
    CHECK_THROWS_AS(snowman(-9999), logic_error);
    CHECK_THROWS_AS(snowman(-999999999), logic_error);
    /* Add more checks here */
}

TEST_CASE("Check Throw message") {
    CHECK_THROWS_WITH_MESSAGE(snowman(5), "Invalid code '5'", "");
    CHECK_THROWS_WITH_MESSAGE(snowman(5050), "Invalid code '5050'", "");
    CHECK_THROWS_WITH_MESSAGE(snowman(-50), "Invalid code '-50'", "");
    CHECK_THROWS_WITH_MESSAGE(snowman(-5050), "Invalid code '-5050'", "");
    CHECK_THROWS_WITH_MESSAGE(snowman(123456789), "Invalid code '123456789'", "");
    CHECK_THROWS_WITH_MESSAGE(snowman(-123456789), "Invalid code '-123456789'", "");
}

TEST_CASE("loop check") {
    for (int n = 2; n < 10; n++) {
        if (n == 8) {
            continue;
        }
        int t = 1;
        int k = 5;
        for (int i = 1; i < n; i++) {
            t = t * 10 + 1;
            k = k * 10 + 1;
        }
        CHECK_THROWS(snowman(k));
        CHECK_THROWS_AS(snowman(t), logic_error);
    }

    int start = 11111111;
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i < 10000001; i *= 10) {
            CHECK_NOTHROW(snowman(start));
            start += i;
        }
    }
}

/* Add more test cases here */
