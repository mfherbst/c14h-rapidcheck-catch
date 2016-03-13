#pragma once
#include <rapidcheck.h>
#include "Vector.hh"

static constexpr size_t maxvecsize = 100;

namespace rc {
template <typename Scalar>
class FixedSizeVector {
  public:
    typedef typename Vector<Scalar>::size_type size_type;
    typedef typename Vector<Scalar>::scalar_type scalar_type;

    static Gen<Vector<Scalar>> fixed_size(size_type n) {
        auto callable = [=] {
            // allocate
            Vector<Scalar> v(n, false);

            // set arbitrary values:
            for (size_type i = 0; i < n; ++i) {
                v[i] = *gen::arbitrary<scalar_type>();
            }

            return v;
        };

        return gen::exec(callable);
    }
};

template <typename Scalar>
struct Arbitrary<Vector<Scalar>> {
    typedef typename Vector<Scalar>::scalar_type scalar_type;
    typedef typename Vector<Scalar>::size_type size_type;

    static Gen<Vector<Scalar>> arbitrary() {
        // Define a lambda that returns a new matrix object.
        auto callable = [] {
            const auto size = *gen::inRange<size_type>(1, maxvecsize + 1);

            Vector<Scalar> v(size, false);

            // set to arbitrary values
            for (size_type i = 0; i < v.size(); ++i) {
                v[i] = *gen::arbitrary<scalar_type>();
            }

            return v;
        };

        // Return the callable wrapped in gen::exec.
        return gen::exec(callable);
    };
};
}  // namespace rc
