#pragma once

#include <memory.h>

#define swap(x, y) do { \
    unsigned char temp[sizeof(x) == sizeof(y) ? sizeof(x) : -1];    \
    memcpy(temp, &y, sizeof(x));                                    \
    memcpy(&y, &x, sizeof(x));                                      \
    memcpy(&x, temp, sizeof(x));                                    \
} while(0)
