set(OPT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/OPT/include/")
set(OPT_LIB_DIR "${CMAKE_SOURCE_DIR}/3rdparty/OPT/lib/")

if(MSVC)
    find_library(OPT_LIBRARY NAMES OPTController PATHS "${CMAKE_SOURCE_DIR}/3rdparty/OPT/lib/" )
elseif(CV_GCC OR CV_CLANG)
    set(OPT_LIBRARY "temp")
endif()

set(OPT_LIBS ${OPT_LIBRARY})

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/OPT/bin/OPTController.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug)