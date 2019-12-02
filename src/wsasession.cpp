//
// Created by zvone on 01-Dec-19.
//
#include "wsasession.h"

#include <winsock2.h>
#include <system_error>
#include <iostream>

WSASession::WSASession() {
  std::cout << "wsasession constructor" << std::endl;
  const int ret = WSAStartup(MAKEWORD(2, 2), &data_);
  if (ret != 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "WSAStartup Failed");
}

WSASession::~WSASession() {
  std::cout << "wsasession destructor" << std::endl;
  WSACleanup();
}

