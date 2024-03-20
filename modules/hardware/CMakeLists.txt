set(the_description "hardware module")
as_add_module(hardware as_core as_io as_data)

set(extra_libs "")

as_glob_module_sources(HEADERS ${ControlCAN_INCLUDE_DIR} ${PLXAPI_INCLUDE_DIR}  ${Boost_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})
include_directories(${LOG_INCLUDE_DIR})
as_module_include_directories(${ControlCAN_INCLUDE_DIR} ${PLXAPI_INCLUDE_DIR}  ${LOG_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})
as_create_module(${ControlCAN_LIB} ${PLXAPI_LIB} ${Boost_LIBRARIES})
target_link_libraries( ${the_module} 
PUBLIC
        optimized ${LOG_LIB}
        debug ${LOG_LIBD}
        )
