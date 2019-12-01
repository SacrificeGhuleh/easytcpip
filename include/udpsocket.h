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
  
  void SendTo(const std::string &address, unsigned short port, const char *buffer, int len, int flags = 0);
  
  void SendTo(sockaddr_in &address, const char *buffer, int len, int flags = 0);
  
  sockaddr_in RecvFrom(char *buffer, int len, int flags = 0);
  
  void Bind(unsigned short port);

private:
  SOCKET sock;
};

#endif //EASYTCPIP_UDPSOCKET_H
