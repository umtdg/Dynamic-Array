#include <dyarrayd/intarray.h>
#include <stdio.h>

#include "fails_codes.h"

static int total = 0;

void foreach_callback(int i) {
    total += i;
}

int test_array_foreach_correct_params() {
    ArrayForeachCallback(int) cb = foreach_callback;

    Array(int) arr;

    ArrayInit(int)(&arr, 8, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, -4);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, -2);
    ArrayAppend(int)(&arr, 5);

    if (!ArrayForeach(int)(&arr, cb)) return FUNCTION_FAILED;

    if (total != 3) return FUNCTION_LOGIC_FAILED;

    return 0;
}

int test_array_foreach_null_callback() {
    Array(int) arr;

    ArrayInit(int)(&arr, 8, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);
    ArrayAppend(int)(&arr, 5);

    if (ArrayForeach(int)(&arr, NULL)) return FUNCTION_SUCCEEDED;

    return 0;
}
