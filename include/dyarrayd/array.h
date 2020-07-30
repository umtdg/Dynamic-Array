#pragma once

#include <stdlib.h>
#include <memory.h>

#ifndef Bool
#define Bool int
#endif

#ifndef True
#define True 1
#endif

#ifndef False
#define False 0
#endif


/* Typedefs for types with spaces */

typedef unsigned char UByte;

typedef signed char Byte;

typedef unsigned short UShort;

typedef unsigned int UInt;

typedef unsigned long ULong;

/* Typedefs for types with spaces */


/* Defaults */

#define ArrayDefaultInitialSize 32

#define ArrayDefaultGrowthRate ArrayDefaultInitialSize

/* Defaults */


// Name of the structure of the array
#define Array(type) Array_##type

// Structure of the array
// Note: members of this structure should not be
// modified outside of the library.
#define ArrayStructure(type) typedef struct {                                       \
    size_t GrowthRate;                                                              \
    type* Buffer;                                                                   \
    size_t Capacity;                                                                \
    size_t Length;                                                                  \
    size_t Size;                                                                    \
} Array(type)


/* Macros for function names */

#define ArrayInit(type) init_##type##_array

#define ArrayExpand(type) expand_##type##_array

#define ArrayDelete(type) delete_##type##_array

#define ArrayAppend(type) append_##type

#define ArraySlice(type) slice_##type##_array

/* Macros for function names */


/* Function declaration macros */

// Initialize the array structure
#define ArrayInitDecl(type)                                                         \
Bool ArrayInit(type)(Array(type)* instance,                                         \
    size_t initialSize,                                                             \
    size_t growthRate                                                               \
)

// Expand the array with realloc.
// The Buffer will be extended by GrowthRate property.
#define ArrayExpandDecl(type) Bool ArrayExpand(type)(Array(type)* instance)

// Free the Buffer pointer and set other properties to default
// Also fills the Buffer with zeroes before free.
#define ArrayDeleteDecl(type) void ArrayDelete(type)(Array(type)* instance)

// Append an item to the Buffer.
// Automatically expands the Buffer if there
// is no space left.
#define ArrayAppendDecl(type) Bool ArrayAppend(type)(Array(type)* instance, type item)

// Slice specified range from array
// If requested slice exceeds the length,
// then slicing will stop at the end.
#define ArraySliceDecl(type) Bool ArraySlice(type)(Array(type)* instance, size_t offset, size_t length)

/* End of function declaration macros */


/* Function body macros */

// Initialize the array structure
#define ArrayInitBody(type)                                                         \
ArrayInitDecl(type) {                                                               \
    initialSize = (initialSize > 0) ? initialSize : ArrayDefaultInitialSize;        \
    growthRate = (growthRate > 0) ? growthRate : ArrayDefaultGrowthRate;            \
                                                                                    \
    instance->Size = sizeof(type) * initialSize;                                    \
    instance->Buffer = (type*)malloc(instance->Size);                               \
    if (!(instance->Buffer)) return False;                                          \
                                                                                    \
    instance->Capacity = initialSize;                                               \
    instance->GrowthRate = growthRate;                                              \
    instance->Length = 0;                                                           \
                                                                                    \
    return True;                                                                    \
}

// Free the Buffer pointer and set other properties to default
// Also fills the Buffer with zeroes before free.
#define ArrayDeleteBody(type)                                                       \
ArrayDeleteDecl(type) {                                                             \
    memset(instance->Buffer, 0, instance->Size);                                    \
    free(instance->Buffer);                                                         \
    instance->Buffer = NULL;                                                        \
    instance->Size = 0;                                                             \
    instance->Length = 0;                                                           \
    instance->Capacity = 0;                                                         \
    instance->GrowthRate = 0;                                                       \
}

// Expand the array with realloc.
// The Buffer will be extended by GrowthRate property.
#define ArrayExpandBody(type)                                                       \
ArrayExpandDecl(type) {                                                             \
    type* temp = (type*)realloc(                                                    \
        instance->Buffer,                                                           \
        sizeof(type) * (instance->Capacity + instance->GrowthRate)                  \
    );                                                                              \
    if (!temp) return False;                                                        \
                                                                                    \
    instance->Capacity += instance->GrowthRate;                                     \
    instance->Buffer = temp;                                                        \
    instance->Size = sizeof(type) * instance->Capacity;                             \
                                                                                    \
    return True;                                                                    \
}

// Append an item to the Buffer.
// Automatically expands the Buffer if there
// is no space left.
#define ArrayAppendBody(type)                                                       \
ArrayAppendDecl(type) {                                                             \
    if (instance->Capacity == instance->Length)                                     \
        if (!(ArrayExpand(type)(instance))) return False;                           \
                                                                                    \
    instance->Buffer[instance->Length] = item;                                      \
    instance->Length++;                                                             \
                                                                                    \
    return True;                                                                    \
}

// Slice specified range from array
// If offset + length exceeds the length of the array,
// returns False.
#define ArraySliceBody(type)                                                        \
ArraySliceDecl(type) {                                                              \
    if (offset >= instance->Length) return False;                                   \
    if (offset + length > instance->Length) return False;                           \
                                                                                    \
    for (size_t i = offset, j = 0; i < offset + length; i++, j++) {                 \
        instance->Buffer[j] = instance->Buffer[i];                                  \
    }                                                                               \
                                                                                    \
    memset(                                                                         \
        instance->Buffer + length,                                 \
        0,                                                                          \
        instance->Size - (sizeof(type) * length)                                    \
    );                                                                              \
                                                                                    \
    instance->Length = length;                                                      \
                                                                                    \
    return True;                                                                    \
}

/* Function body macros */


/* Macros for .h and .c files */

#define MakeArrayHeadingFile(type)      \
ArrayStructure(type);                   \
ArrayInitDecl(type);                    \
ArrayDeleteDecl(type);                  \
ArrayExpandDecl(type);                  \
ArrayAppendDecl(type);                  \
ArraySliceDecl(type)

// Should include the header file created by
// MakeArrayHeadingFile macro
#define MakeArraySourceFile(type)       \
ArrayInitBody(type);                    \
ArrayDeleteBody(type);                  \
ArrayExpandBody(type);                  \
ArrayAppendBody(type);                  \
ArraySliceBody(type)

/* Macros for .h and .c files */
