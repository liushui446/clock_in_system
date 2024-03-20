set(HIK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/HIK/HIKinclude/")
set(HIK_LIB_DIR "${CMAKE_SOURCE_DIR}/3rdparty/HIK/HIKinclude/lib64/")

if(MSVC)
    find_library(HIK_LIBRARY1 NAMES MvCameraControl PATHS "${CMAKE_SOURCE_DIR}/3rdparty/HIK/HIKinclude/lib64/" )
    find_library(OPT_LIBRARY1 NAMES OPTController PATHS "${CMAKE_SOURCE_DIR}/3rdparty/HIK/HIKinclude/lib64/" )
elseif(CV_GCC OR CV_CLANG)
    set(HIK_LIBRARY1 "temp")
    set(OPT_LIBRARY1 "temp")
endif()

set(HIK_LIBS ${HIK_LIBRARY1})
set(OPT_LIBS ${OPT_LIBRARY1})

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/HIK/Debug DESTINATION ${PROJECT_BINARY_DIR}/bin/)
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/HIK/Release DESTINATION ${PROJECT_BINARY_DIR}/bin/)