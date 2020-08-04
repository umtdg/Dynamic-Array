#include <dyarrayd/auxiliary.h>

#include "fails_codes.h"

int test_array_auxiliary_swap_floats() {
    float x = 3.0f;
    float y = 2.0f;

    swap(x, y);

    if (x != 2.0f) return NOT_EQUAL;
    if (y != 3.0f) return NOT_EQUAL;

    return 0;
}

int test_array_auxiliary_swap_structures() {
    struct test {
        int val1;
        int val2;
        int val3;
    };

    struct test x = {0, 1, 2};
    struct test y = {9, 8, 7};

    swap(x, y);

    if (x.val1 != 9) return NOT_EQUAL;
    if (x.val2 != 8) return NOT_EQUAL;
    if (x.val3 != 7) return NOT_EQUAL;

    if (y.val1 != 0) return NOT_EQUAL;
    if (y.val2 != 1) return NOT_EQUAL;
    if (y.val3 != 2) return NOT_EQUAL;

    return 0;
}
