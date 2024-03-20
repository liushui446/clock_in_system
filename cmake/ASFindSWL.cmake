set(SWL470x_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/")
set(SWL470x_LIB_DIR "${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/lib/x64/")
set(SWL470x_LIB "${SWL470x_LIB_DIR}/dlpc-swl-api.lib")

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/bin/x64/dlpc-swl-api.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug)
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/bin/x64/dlpc-swl-api.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Release)

file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/bin/x64/cyusbserial.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug)
file(COPY ${CMAKE_SOURCE_DIR}/3rdparty/SWL-SDI470X/bin/x64/cyusbserial.dll DESTINATION ${PROJECT_BINARY_DIR}/bin/Release)