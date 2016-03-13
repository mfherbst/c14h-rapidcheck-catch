#include "factorial.hh"

double factorial(size_t i) {
    if (i == 0) {
        return 1.;
    } else if (i == 1) {
        return 1.;
    } else if (i == 2) {
        return 2.;
    } else if (i == 3) {
        return 3.;
    } else if (i == 4) {
        return 24.;
    } else {
        return i * factorial(i - 1);
    }
}
