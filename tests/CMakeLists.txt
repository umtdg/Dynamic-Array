add_executable(dyarrayd-test
        tests.c
        test_init.h
        test_expand.h
        fails_codes.h
        test_delete.h
        test_append.h
        test_slice.h
        test_foreach.h
        test_pop.h
        test_map.h
        test_swap.h
        test_reverse.h
        test_copy.h
        test_clear.h)

target_link_libraries(dyarrayd-test PRIVATE dyarrayd)
