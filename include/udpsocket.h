//
// Created by zvone on 01-Dec-19.
//
#ifndef EASYTCPIP_UDPSOCKET_H
#define EASYTCPIP_UDPSOCKET_H

#include <winsock2.h>
#include <string>
#include <memory>

class WSASession;

class UDPSocket {
public:
  UDPSocket();
  
  ~UDPSocket();
  
  void sendto(const std::string &address, unsigned short port, const char *buffer, int len, int flags = 0);
  
  void sendto(sockaddr_in &address, const char *buffer, int len, int flags = 0);
  
  sockaddr_in recvfrom(char *buffer, int len, int flags = 0);
  
  sockaddr_in bind(unsigned short port);
  
  void setSendToBroadcast(bool val);
  
  void setOptReadTimeout(DWORD read_timeout);

private:
  SOCKET socket_;
  
  std::unique_ptr<WSASession> session_;
};

#endif //EASYTCPIP_UDPSOCKET_H
