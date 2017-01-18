#pragma once
#include <complex>
#include <type_traits>

template <typename T, typename U,
          typename Common = typename std::common_type<T, U>::type>
bool num_equal(const T& lhs, const U& rhs, const long double tolerance) {
    // This is a copy of the algorithm used in the krims
    // NumComp and NumEqual classes. For more details see
    // https://github.com/linalgwrap/krims/blob/master/src/krims/NumComp/NumEqual.hh

    const Common absdiff = std::abs(lhs - rhs);
    const Common maxside = std::max<Common>(std::abs(lhs), std::abs(rhs));
    const Common maxone = std::max<Common>(1, maxside);
    return absdiff <= tolerance * maxone;
}
