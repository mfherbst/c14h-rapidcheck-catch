#include "catch.hpp"
#include "Vector.hh"
#include "extra_generators.hh"
#include <rapidcheck.h>

template <typename Scalar>
void showValue(const Vector<Scalar>& v, std::ostream& os) {
    typename Vector<Scalar>::size_type i = 0;

    for (; i < v.size() - 1; ++i) {
        os << v[i] << "   ";
    }
    os << v[i];
}

TEST_CASE("Test Vector", "[vector]") {
    using namespace rc;

    typedef double scalar_type;
    typedef Vector<scalar_type> vector_type;
    typedef typename vector_type::size_type size_type;

    SECTION("Test Vector construction") {
        auto testlambda = [] {
            auto s = *gen::inRange<size_type>(0, maxvecsize + 1);
            vector_type v{s};
            RC_ASSERT(v.size() == s);
        };

        rc::check("Test Vector construction", testlambda);
    }

    SECTION("Test Vector element access") {
        auto testlambda = [](vector_type v) {
            auto modify = *gen::inRange<size_t>(0, v.size());
            auto newval = *gen::arbitrary<scalar_type>();

            vector_type vcopy{v};

            v[modify] = newval;

            for (size_type i = 0; i < v.size(); ++i) {
                if (i == modify) {
                    RC_ASSERT(v[i] == newval);
                } else {
                    RC_ASSERT(v[i] == vcopy[i]);
                }
            }
        };
        REQUIRE(rc::check("Test Vector element access", testlambda));
    }

    SECTION("Test Vector addition") {
        auto testlambda = [](vector_type v) {
            auto other = *FixedSizeVector<scalar_type>::fixed_size(v.size());
            auto sum = v + other;

            for (size_type i = 0; i < v.size(); ++i) {
                RC_ASSERT(sum[i] == v[i] + other[i]);
            }
        };

        rc::check("Test vector addition", testlambda);
    }

    SECTION("Test Vector subtraction") {
        auto testlambda = [](vector_type v) {
            auto other = *FixedSizeVector<scalar_type>::fixed_size(v.size());
            auto sum = v - other;

            for (size_type i = 0; i < v.size(); ++i) {
                RC_ASSERT(sum[i] == v[i] - other[i]);
            }
        };

        rc::check("Test vector subtraction", testlambda);
    }
}
