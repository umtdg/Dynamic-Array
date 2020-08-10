#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_clear() {
    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (!ArrayClear(int)(&arr)) return FUNCTION_FAILED;

    if (arr.Length != 0) return NONZERO_LENGTH;
    if (arr.Size != 0) return WRONG_SIZE;

    return 0;
}
