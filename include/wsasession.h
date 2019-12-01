//
// Created by zvone on 01-Dec-19.
//

#ifndef EASYTCPIP_WSASESSION_H
#define EASYTCPIP_WSASESSION_H

#include <ws2tcpip.h>

class WSASession {
public:
  WSASession();
  
  ~WSASession();

private:
  WSAData data;
};

#endif //EASYTCPIP_WSASESSION_H
