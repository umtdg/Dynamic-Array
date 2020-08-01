#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_pop_with_null_last() {
    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (!ArrayPop(int)(&arr, NULL)) return FUNCTION_FAILED;

    if (arr.Length != 3) return WRONG_LENGTH;
    if (arr.Buffer[arr.Length] != 0) return ITEM_ERROR;

    return 0;
}

int test_array_pop_with_nonnull_last() {
    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    int last = 0;

    if (!ArrayPop(int)(&arr, &last)) return FUNCTION_FAILED;

    if (arr.Length != 3) return WRONG_LENGTH;
    if (arr.Buffer[arr.Length] != 0) return ITEM_ERROR;
    if (last != 4) return ITEM_ERROR;

    return 0;
}
