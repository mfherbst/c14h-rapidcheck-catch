#include "catch.hpp"
#include "factorial.hh"
#include <rapidcheck.h>

// Put two tests here:
// 	- a few examples
// 	- a complete random test

TEST_CASE("Factorial", "[factorial]") {
    SECTION("A few examples") {
        REQUIRE(factorial(1) == 1.);
        REQUIRE(factorial(4) == 4. * 3. * 2. * 1.);
    }

    SECTION("Random test") {
        auto wurst = [] {
            auto number = *rc::gen::inRange<size_t>(0, 11);

            double result = 1.;
            for (size_t i = 2; i <= number; ++i) {
                result *= i;
            }

            RC_ASSERT(result == factorial(number));
        };

        REQUIRE(rc::check("Random test of factorial", wurst));
    }
}
