//
// Created by zvone on 01-Dec-19.
//
#include <udpsocket.h>

#include <winsock2.h>
#include <system_error>
#include <string>
#include "wsasession.h"

UDPSocket::UDPSocket() {
  session_ = std::make_unique<WSASession>();
  socket_ = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket_ == INVALID_SOCKET)
    throw std::system_error(WSAGetLastError(), std::system_category(), "Error opening socket");
  
  DWORD read_timeout = 10;
  ::setsockopt(socket_, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char *>(&read_timeout), sizeof read_timeout);
}

UDPSocket::~UDPSocket() {
  ::closesocket(socket_);
}

void UDPSocket::sendto(const std::string &address, unsigned short port, const char *buffer, int len, int flags) {
  sockaddr_in add;
  add.sin_family = AF_INET;
  add.sin_addr.s_addr = ::inet_addr(address.c_str());
  add.sin_port = ::htons(port);
  int ret = ::sendto(socket_, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&add), sizeof(add));
  if (ret < 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "sendto failed");
}

void UDPSocket::sendto(sockaddr_in &address, const char *buffer, int len, int flags) {
  int ret = ::sendto(socket_, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&address), sizeof(address));
  if (ret < 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "sendto failed");
}

sockaddr_in UDPSocket::recvfrom(char *buffer, int len, int flags) {
  sockaddr_in from;
  int size = sizeof(from);
  int ret = ::recvfrom(socket_, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&from), &size);
  if (ret < 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "recvfrom failed");
  
  // make the buffer zero terminated
  buffer[ret] = 0;
  return from;
}

sockaddr_in UDPSocket::bind(unsigned short port) {
  sockaddr_in add;
  add.sin_family = AF_INET;
  add.sin_addr.s_addr = ::htonl(INADDR_ANY);
  add.sin_port = ::htons(port);
  
  int ret = ::bind(socket_, reinterpret_cast<SOCKADDR *>(&add), sizeof(add));
  if (ret < 0)
    throw std::system_error(WSAGetLastError(), std::system_category(), "bind failed");
  return add;
}


void UDPSocket::setSendToBroadcast(bool val ){
  char broadcast = val;
  ::setsockopt(socket_, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));
}