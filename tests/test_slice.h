#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_slice_correct_params() {
    int expected[] = {4, 5, 6};

    Array(int) arr;

    ArrayInit(int)(&arr, 8, 8);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);
    ArrayAppend(int)(&arr, 5);
    ArrayAppend(int)(&arr, 6);
    ArrayAppend(int)(&arr, 7);

    if (!ArraySlice(int)(&arr, 3, 3)) return FUNCTION_FAILED;

    if (!arr.Buffer) return BUFFER_NULL;
    if (arr.Length != 3) return WRONG_LENGTH;
    for (size_t i = 0; i < arr.Length; i++) {
        if (expected[i] != arr.Buffer[i]) {
            return ITEM_ERROR;
        }
    }

    return 0;
}

int test_array_slice_incorrect_offset() {
    Array(int) arr;

    ArrayInit(int)(&arr, 8, 8);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);

    if (ArraySlice(int)(&arr, 4, 3)) return FUNCTION_SUCCEEDED;

    if (!arr.Buffer) return BUFFER_NULL;
    if (arr.Length != 3) return WRONG_LENGTH;

    return 0;
}

int test_array_slice_exceed_length() {
    Array(int) arr;

    ArrayInit(int)(&arr, 8, 8);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);

    if (ArraySlice(int)(&arr, 0, 4)) return FUNCTION_SUCCEEDED;

    if (!arr.Buffer) return BUFFER_NULL;
    if (arr.Length != 3) return WRONG_LENGTH;

    return 0;
}
