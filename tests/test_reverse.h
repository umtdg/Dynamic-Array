#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_reverse() {
    Array(int) arr;

    int expected[] = {6, 5, 4, 3, 2, 1};

    ArrayInit(int)(&arr, ArrayDefaultInitialSize, ArrayDefaultGrowthRate);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);
    ArrayAppend(int)(&arr, 5);
    ArrayAppend(int)(&arr, 6);

    if (!ArrayReverse(int)(&arr)) return FUNCTION_FAILED;

    for (size_t i = 0; i < arr.Length; i++) {
        if (arr.Buffer[i] != expected[i]) return ITEM_ERROR;
    }

    return 0;
}
