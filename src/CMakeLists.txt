set(INCLUDE_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
set(INCLUDE_DYARRAYD "${INCLUDE_DIRECTORY}/dyarrayd")

set(HEADER_LIST
        "${INCLUDE_DYARRAYD}/array.h"
        "${INCLUDE_DYARRAYD}/bytearray.h"
        "${INCLUDE_DYARRAYD}/intarray.h"
        "${INCLUDE_DYARRAYD}/longarray.h"
        "${INCLUDE_DYARRAYD}/shortarray.h"
        "${INCLUDE_DYARRAYD}/uintarray.h"
        "${INCLUDE_DYARRAYD}/ulongarray.h"
        "${INCLUDE_DYARRAYD}/ushortarray.h")

set(SOURCE_LIST
        "bytearray.c"
        "intarray.c"
        "longarray.c"
        "shortarray.c"
        "uintarray.c"
        "ulongarray.c"
        "ushortarray.c")

add_library(dyarrayd ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(dyarrayd PUBLIC ../include)

source_group(TREE ${INCLUDE_DIRECTORY} PREFIX "Header Files" FILES ${HEADER_LIST})
