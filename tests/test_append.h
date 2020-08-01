#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_append() {
    int expected[] = {1, 2, 3, 4, 5};

    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    ArrayAppend(int)(&arr, 1);
    ArrayAppend(int)(&arr, 2);
    ArrayAppend(int)(&arr, 3);
    ArrayAppend(int)(&arr, 4);

    if (!ArrayAppend(int)(&arr, 5)) return FUNCTION_FAILED; // Should expand

    if (arr.Length != 5) return WRONG_LENGTH;
    if (arr.Capacity != 8) return WRONG_CAPACITY;
    if (arr.Size != sizeof(int) * 8) return WRONG_SIZE;
    for (size_t i = 0; i < arr.Length; i++) {
        if (expected[i] != arr.Buffer[i]) {
            return ITEM_ERROR;
        }
    }

    return 0;
}
