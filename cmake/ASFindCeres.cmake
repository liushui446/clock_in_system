set(Ceres_DIR "${CMAKE_SOURCE_DIR}/3rdparty/Ceres/CMake")

find_package(Ceres REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/Ceres/bin/ceres.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug)
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/Ceres/bin/ceres-debug.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug)