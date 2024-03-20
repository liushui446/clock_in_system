set(the_description "camera module")
#as_define_module(camera as_core)
as_add_module(camera as_core as_data as_io)

set(extra_libs "")

find_package(OpenMP)
if(OpenMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


file(GLOB_RECURSE lib_hdrs_lib
    "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/include/*.h"   
)

as_glob_module_sources(HEADERS ${OpenCV_INCLUDE_DIRS} ${lib_hdrs_lib} ${LOG_INCLUDE_DIR} ${HIK_INCLUDE_DIR} ${OPT_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})

include_directories(${LOG_INCLUDE_DIR})

as_module_include_directories(${lib_hdrs_lib} ${OpenCV_INCLUDE_DIRS} ${LOG_INCLUDE_DIR} ${HIK_INCLUDE_DIR} ${OPT_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})
list(APPEND extra_libs ${OpenCV_LIBS} ${HIK_LIBS} ${OPT_LIBS})

#add_compile_definitions(TIXML_EXPORTS)

as_source_group("Include" DIRBASE "${CMAKE_CURRENT_LIST_DIR}/include" 
                FILES ${lib_hdrs_lib})


as_create_module(${extra_libs})

target_link_libraries(${the_module} PUBLIC
        debug ${LOG_LIBD}
        optimized ${LOG_LIB}
        debug ${HIK_LIBS}
        optimized ${HIK_LIBS}
        debug ${OPT_LIBS}
        optimized ${OPT_LIBS}
        yaml-cpp)
