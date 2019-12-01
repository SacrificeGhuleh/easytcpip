cmake_minimum_required(VERSION 3.15)
project(easytcpip)

set(CMAKE_CXX_STANDARD 14)



set(SOURCE_DIR src)
set(HEADER_DIR include)
set(EXAMPLE_DIR examples)

set(HEADER_FILES
    ${HEADER_DIR}
    )

set(SOURCE_FILES
    ${SOURCE_DIR})

set(EXAMPLE_FILES
    ${EXAMPLE_DIR}/udpclient.cpp
    ${EXAMPLE_DIR}/udpserver.cpp
    )

include_directories(${HEADER_DIR})

add_executable(UdpClientExample ${HEADER_FILES} ${SOURCE_FILES} ${EXAMPLE_DIR}/udpclient.cpp)
add_executable(UdpServerExample ${HEADER_FILES} ${SOURCE_FILES} ${EXAMPLE_DIR}/udpserver.cpp)

add_executable(easytcpip main.cpp examples/udpserver.cpp)