//
// Created by zvone on 01-Dec-19.
//
#include <wsasession.h>

#include <winsock2.h>
#include <system_error>

WSASession::WSASession() {
  const int ret = WSAStartup(MAKEWORD(2, 2), &data_);
  if (ret != 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "WSAStartup Failed");
}

WSASession::~WSASession() {
  WSACleanup();
}

