list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/3rdparty/Suitesparse/lapack_windows/x64")

set(Suitesparse_DIR "${CMAKE_SOURCE_DIR}/3rdparty/Suitesparse/lib/cmake/suitesparse-5.4.0")
find_package(Suitesparse REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/Suitesparse/lapack_windows/Debug DESTINATION ${PROJECT_BINARY_DIR}/bin/)