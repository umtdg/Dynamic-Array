#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_copy_offset_overflow() {
    Array(int) arr;
    Array(int) arr2;

    ArrayInit(int)(&arr, 4, 4);
    ArrayInit(int)(&arr2, 8, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (ArrayCopy(int)(&arr, &arr2, 4, 1)) return FUNCTION_SUCCEEDED;

    return 0;
}

int test_array_copy_count_overflow() {
    Array(int) arr;
    Array(int) arr2;

    ArrayInit(int)(&arr, 4, 4);
    ArrayInit(int)(&arr2, 8, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (ArrayCopy(int)(&arr, &arr2, 0, 5)) return FUNCTION_SUCCEEDED;

    return 0;
}

int test_array_copy_correct_params() {
    int expected[] = {2, 3};

    Array(int) arr;
    Array(int) arr2;

    ArrayInit(int)(&arr, 4, 4);
    ArrayInit(int)(&arr2, 8, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (!ArrayCopy(int)(&arr, &arr2, 1, 2)) return FUNCTION_FAILED;

    if (arr2.Length != 2) return WRONG_LENGTH;
    if (arr2.Capacity != 8) return WRONG_CAPACITY;

    for (size_t i = 0; i < arr2.Length; i++) {
        if (arr2.Buffer[i] != expected[i]) {
            return ITEM_ERROR;
        }
    }

    return 0;
}
