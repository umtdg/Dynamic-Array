#include "test_init.h"
#include "test_expand.h"
#include "test_delete.h"
#include "test_append.h"
#include "test_slice.h"
#include "test_foreach.h"
#include "test_pop.h"
#include "test_map.h"
#include "test_swap.h"
#include "test_reverse.h"
#include "test_clear.h"
#include "test_copy.h"
#include "fails_codes.h"

#include <time.h>
#include <stdio.h>

#define SUCCESS_STRING  "PASSED"
#define FAIL_STRING     "FAILED"

typedef int (*testcase)();

static clock_t start, end;
static int succeeded_test_count;
static int total_test_count;

void run_test(testcase f, const char* name) {
    printf("%s ... ", name);

    start = clock();

    int res = f();

    end = clock();

    if (res == 0) {
        printf(SUCCESS_STRING);
        succeeded_test_count++;
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
                break;
            case FUNCTION_FAILED:
                printf(" Function returned False");
                break;
            case FUNCTION_SUCCEEDED:
                printf("Function returned True");
                break;
            case FUNCTION_LOGIC_FAILED:
                printf(" Unexpected function execution");
                break;
            case ITEM_ERROR:
                printf(" Unmatched items");
                break;
            case NOT_EQUAL:
                printf(" Values are not equal, expected equal");
                break;
            case EQUAL:
                printf(" Values are equal, expected not equal");
                break;
            default:
                break;
        }
    }

    total_test_count++;

    printf(" %f ms\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

int main() {
    succeeded_test_count = total_test_count = 0;

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
    run_test(test_array_map_correct_params, "test_array_map_correct_params");
    run_test(test_array_map_null_callback, "test_array_map_null_callback");
    run_test(test_array_auxiliary_swap_floats, "test_array_auxiliary_swap_floats");
    run_test(test_array_auxiliary_swap_structures, "test_array_auxiliary_swap_structures");
    run_test(test_array_reverse, "test_array_reverse");
    run_test(test_array_clear, "test_array_clear");
    run_test(test_array_copy_offset_overflow, "test_array_copy_offset_overflow");
    run_test(test_array_copy_count_overflow, "test_array_copy_count_overflow");
    run_test(test_array_copy_correct_params, "test_array_copy_correct_params");

    printf("\n%d/%d of tests passed\n", succeeded_test_count, total_test_count);

    return 0;
}
