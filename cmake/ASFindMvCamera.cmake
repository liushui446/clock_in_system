set(HIK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/MvCamera/Includes/")
set(HIK_LIB_DIR "${CMAKE_SOURCE_DIR}/3rdparty/MvCamera/Libraries/win64/")

if(MSVC)
    find_library(HIK_LIBRARY1 NAMES MvCameraControl PATHS "${CMAKE_SOURCE_DIR}/3rdparty/MvCamera/Libraries/win64/" )
elseif(CV_GCC OR CV_CLANG)
    set(HIK_LIBRARY1 "temp")
endif()

set(HIK_LIBS ${HIK_LIBRARY1})