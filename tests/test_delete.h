#include <dyarrayd/intarray.h>

#include "fails_codes.h"

int test_array_delete() {
    Array(int) arr;

    ArrayInit(int)(&arr, ArrayDefaultInitialSize, ArrayDefaultGrowthRate);

    ArrayDelete(int)(&arr);

    if (arr.Buffer) return BUFFER_NOT_NULL;
    if (arr.Length != 0) return NONZERO_LENGTH;
    if (arr.Capacity != 0) return WRONG_CAPACITY;
    if (arr.GrowthRate != 0) return WRONG_GROWTH_RATE;
    if (arr.Size != 0) return WRONG_SIZE;

    return 0;
}
