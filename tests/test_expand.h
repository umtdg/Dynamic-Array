#include <dyarrayd/intarray.h>
#include "fails_codes.h"

int test_array_expand() {
    Array(int) arr;

    ArrayInit(int)(&arr, 4, 4);

    if (!ArrayExpand(int)(&arr)) return FUNCTION_FAILED;

    if (!arr.Buffer) return BUFFER_NULL;
    if (arr.Length != 0) return NONZERO_LENGTH;
    if (arr.Capacity != 8) return WRONG_CAPACITY;
    if (arr.Size != sizeof(int) * 8) return WRONG_SIZE;

    return 0;
}
