#include <dyarrayd/intarray.h>
#include "fails_codes.h"


int test_array_init() {
    Array(int) arr;

    if (!ArrayInit(int)(&arr, 4, 8)) return FUNCTION_FAILED;

    if (!arr.Buffer) return BUFFER_NULL;
    if (arr.Length != 0) return NONZERO_LENGTH;
    if (arr.Capacity != 4) return WRONG_CAPACITY;
    if (arr.GrowthRate != 8) return WRONG_GROWTH_RATE;
    if (arr.Size != sizeof(int) * 4) return WRONG_SIZE;

    return 0;
}
