#include "test_init.h"
#include "test_expand.h"
#include "test_delete.h"
#include "test_append.h"
#include "test_slice.h"
#include "test_foreach.h"
#include "test_pop.h"
#include "fails_codes.h"

#include <time.h>
#include <stdio.h>

#define SUCCESS_STRING  "PASSED"
#define FAIL_STRING     "FAILED"

typedef int (*testcase)();

static clock_t start, end;

void run_test(testcase f, const char* name) {
    printf("%s ... ", name);

    start = clock();

    int res = f();

    end = clock();

    if (res == 0) {
        printf(SUCCESS_STRING);
    }
    else {
        printf(FAIL_STRING);
        switch (res) {
            case BUFFER_NULL:
                printf(" Buffer should not be null");
                break;
            case BUFFER_NOT_NULL:
                printf(" Buffer should be null");
            case NONZERO_LENGTH:
                printf(" Incorrect length");
                break;
            case WRONG_CAPACITY:
                printf(" Incorrect capacity");
                break;
            case WRONG_GROWTH_RATE:
                printf(" Incorrect growth rate");
                break;
            case WRONG_SIZE:
                printf(" Incorrect size");
                break;
            case WRONG_LENGTH:
                printf(" Incorrect length");
            case FUNCTION_FAILED:
                printf(" Function returned False");
            case FUNCTION_SUCCEEDED:
                printf("Function returned True");
            case FUNCTION_LOGIC_FAILED:
                printf(" Unexpected function execution");
            case ITEM_ERROR:
                printf(" Unmatched items");
            default:
                break;
        }
    }

    printf(" %f ms\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

int main() {
    run_test(test_array_init, "test_array_init");
    run_test(test_array_expand, "test_array_expand");
    run_test(test_array_delete, "test_array_delete");
    run_test(test_array_append, "test_array_append");
    run_test(test_array_slice_correct_params, "test_array_slice_correct_params");
    run_test(test_array_slice_incorrect_offset, "test_array_slice_incorrect_offset");
    run_test(test_array_slice_exceed_length, "test_array_slice_exceed_length");
    run_test(test_array_foreach_correct_params, "test_array_foreach_correct_params");
    run_test(test_array_foreach_null_callback, "test_array_foreach_null_callback");
    run_test(test_array_pop_with_null_last, "test_array_pop_with_null_last");
    run_test(test_array_pop_with_nonnull_last, "test_array_pop_with_nonnull_last");

    return 0;
}
