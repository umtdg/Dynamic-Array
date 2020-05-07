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
#define ArrayStructure(type) typedef struct { \
    size_t GrowthRate; \
    type* Buffer; \
    size_t Capacity; \
    size_t Length; \
    size_t Size; \
} Array(type)


/* Macros for function names */

#define ArrayInitFunction(type) init_##type##_array

#define ArrayExpandFunction(type) expand_##type##_array

#define ArrayDeleteFunction(type) delete_##type##_array

#define ArrayAppendFunction(type) append_##type

/* Macros for function names */


/* Function declaration macros */

// Initialize the array structure
#define ArrayInitFunctionDeclaration(type) Bool ArrayInitFunction(type)(Array(type)* instance, \
    size_t capacity, \
    size_t initialSize, \
    size_t growthRate)

// Expand the array with realloc.
// The Buffer will be extended by GrowthRate property.
#define ArrayExpandFunctionDeclaration(type) Bool ArrayExpandFunction(type)(Array(type)* instance)

// Free the Buffer pointer and set other properties to default
// Also fills the Buffer with zeroes before free.
#define ArrayDeleteFunctionDeclaration(type) void ArrayDeleteFunction(type)(Array(type)* instance)

// Append an item to the Buffer.
// Automatically expands the Buffer if there
// is no space left.
#define ArrayAppendFunctionDeclaration(type) Bool ArrayAppendFunction(type)(Array(type)* instance, type item)

/* End of function declaration macros */


/* Function body macros */

// Initialize the array structure
#define ArrayInitFunctionBody(type) ArrayInitFunctionDeclaration(type) { \
    initialSize = (initialSize > 0) ? initialSize : ArrayDefaultInitialSize; \
    growthRate = (growthRate > 0) ? growthRate : ArrayDefaultGrowthRate; \
    \
    instance->Size = sizeof(type) * initialSize; \
    instance->Buffer = (type*)malloc(instance->Size); \
    if (!(instance->Buffer)) return False; \
    \
    instance->Capacity = initialSize; \
    instance->GrowthRate = growthRate; \
    instance->Length = 0; \
    \
    return True; \
}

// Free the Buffer pointer and set other properties to default
// Also fills the Buffer with zeroes before free.
#define ArrayDeleteFunctionBody(type) ArrayDeleteFunctionDeclaration(type) { \
    memset(instance->Buffer, 0, sizeof(type) * instance->Capacity); \
    free(instance->Buffer); \
    instance->Buffer = NULL; \
    instance->Size = 0; \
    instance->Length = 0; \
    instance->Capacity = 0; \
    instance->GrowthRate = 0; \
}

// Expand the array with realloc.
// The Buffer will be extended by GrowthRate property.
#define ArrayExpandFunctionBody(type) ArrayExpandFunctionDeclaration(type) { \
    type* temp = (type*)realloc( \
        instance->Buffer, \
        sizeof(type) * (instance->Capacity + instance->GrowthRate) \
    ); \
    if (!temp) return False; \
    \
    instance->Capacity += instance->GrowthRate; \
    instance->Buffer = temp; \
    instance->Size = sizeof(type) * instance->Capacity; \
    \
    return True; \
}

// Append an item to the Buffer.
// Automatically expands the Buffer if there
// is no space left.
#define ArrayAppendFunctionBody(type) ArrayAppendFunctionDeclaration(type) { \
    if (instance->Capacity == instance->Length) \
    { \
        if (!(ArrayExpandFunction(type)(instance))) return False; \
    } \
    \
    instance->Buffer[instance->Length] = item; \
    instance->Length++; \
    \
    return True; \
}

/* Function body macros */


/* Macros for .h and .c files */

#define MakeArrayHeadingFile(type) \
ArrayStructure(type); \
ArrayInitFunctionDeclaration(type); \
ArrayDeleteFunctionDeclaration(type); \
ArrayExpandFunctionDeclaration(type); \
ArrayAppendFunctionDeclaration(type)

// Should include the header file created by
// MakeArrayHeadingFile macro
#define MakeArraySourceFile(type) \
ArrayInitFunctionBody(type); \
ArrayDeleteFunctionBody(type); \
ArrayExpandFunctionBody(type); \
ArrayAppendFunctionBody(type)

/* Macros for .h and .c files */
