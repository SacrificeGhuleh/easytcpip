cmake_minimum_required(VERSION 3.15)
project(easytcpip)

set(CMAKE_CXX_STANDARD 14)

set(EASYTCPIP_SOURCE_DIR src)
set(EASYTCPIP_HEADER_DIR include)
set(EASYTCPIP_EXAMPLE_DIR examples)

set(EASYTCPIP_HEADER_FILES
    ${EASYTCPIP_HEADER_DIR}/udpsocket.h
    )

set(EASYTCPIP_SOURCE_FILES
    ${EASYTCPIP_SOURCE_DIR}/udpsocket.cpp
    ${EASYTCPIP_SOURCE_DIR}/wsasession.cpp
    )

set(EASYTCPIP_EXAMPLE_FILES
    ${EASYTCPIP_EXAMPLE_DIR}/udpclient.cpp
    ${EASYTCPIP_EXAMPLE_DIR}/udpserver.cpp
    )

include_directories(${EASYTCPIP_HEADER_DIR})

add_library(${PROJECT_NAME} ${EASYTCPIP_HEADER_FILES} ${EASYTCPIP_SOURCE_FILES})

add_executable(UdpClientExample ${EASYTCPIP_EXAMPLE_DIR}/udpclient.cpp)
add_executable(UdpServerExample ${EASYTCPIP_EXAMPLE_DIR}/udpserver.cpp)

if (WIN32)
  target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
  target_link_libraries(UdpClientExample wsock32 ws2_32 ${PROJECT_NAME})
  target_link_libraries(UdpServerExample wsock32 ws2_32 ${PROJECT_NAME})
endif ()