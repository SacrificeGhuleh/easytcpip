//
// Created by zvone on 01-Dec-19.
//

#ifndef EASYTCPIP_UDPSOCKET_H
#define EASYTCPIP_UDPSOCKET_H


#include <winsock2.h>
#include <string>

class UDPSocket {
public:
  UDPSocket();
  
  ~UDPSocket();
  
  void sendTo(const std::string &address, unsigned short port, const char *buffer, int len, int flags = 0);
  
  void sendTo(sockaddr_in &address, const char *buffer, int len, int flags = 0);
  
  sockaddr_in recvFrom(char *buffer, int len, int flags = 0);
  
  void bind(unsigned short port);

private:
  SOCKET socket_;
};

#endif //EASYTCPIP_UDPSOCKET_H
