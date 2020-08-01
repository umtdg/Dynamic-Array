#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int twice(int item) {
    return item * 2;
}

int test_array_map_correct_params() {
    int expected[] = {2, 4, 6, 8};

    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (!ArrayMap(int)(&arr, twice)) return FUNCTION_FAILED;

    for (size_t i = 0; i < arr.Length; i++) {
        if (arr.Buffer[i] != expected[i]) return ITEM_ERROR;
    }

    return 0;
}

int test_array_map_null_callback() {
    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (ArrayMap(int)(&arr, NULL)) return FUNCTION_SUCCEEDED;

    return 0;
}
