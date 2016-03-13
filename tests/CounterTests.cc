#include "catch.hpp"
#include <rapidcheck.h>
#include <rapidcheck/state.h>
#include "Counter.hh"

// #define HAVE_CLASSIFY

namespace counter_testing {

// The model to test against:
struct CounterModel {
    long value;
};

struct Increment : rc::state::Command<CounterModel, Counter> {
    typedef CounterModel model_type;
    typedef Counter sut_type;

    void apply(model_type& model) const override {
        // here we check wheather the operation can be sensibly applied
        // via RC_PRE
        model.value += 1;
    }

    void run(const model_type& model, sut_type& sut) const override {
// The model is the state before running the test

#ifdef HAVE_CLASSIFY
        RC_CLASSIFY(true, "Increment");
#endif

        // perform the operation:
        sut.increment();

        // check that the result is sensible:
        RC_ASSERT(sut() == model.value + 1);
    }

    void show(std::ostream& os) const override { os << "Increment"; }
};

struct Decrement : rc::state::Command<CounterModel, Counter> {
    typedef CounterModel model_type;
    typedef Counter sut_type;

    void apply(model_type& model) const override {
        // here we check wheather the operation can be sensibly applied
        // via RC_PRE
        model.value -= 1;
    }

    void run(const model_type& model, sut_type& sut) const override {
// The model is the state before running the test

#ifdef HAVE_CLASSIFY
        RC_CLASSIFY(true, "Decrement");
#endif

        // perform the operation:
        sut.decrement();

        // check that the result is sensible:
        RC_ASSERT(sut() == model.value - 1);
    }

    void show(std::ostream& os) const override { os << "Decrement"; }
};
}

void showValue(const Counter& c, std::ostream& os) {
    os << "Counter(" << c() << ")";
}

//
// ---------------------------------------------------------------
//

TEST_CASE("Test the counter", "[counter]") {
    SECTION("Test") {
        using namespace counter_testing;
        using namespace rc;

        auto random_test = [] {
            Counter sut;
            CounterModel model;
            model.value = sut.value();

            auto genCommands = state::gen::execOneOf<Increment, Decrement>;

            state::check(model, sut, genCommands);
        };

        REQUIRE(rc::check("State test of the counter.", random_test));
    }
}
