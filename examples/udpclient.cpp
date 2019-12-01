//
// Created by zvone on 01-Dec-19.
//


#include <udpsocket.h>
#include <wsasession.h>

#include <exception>
#include <iostream>
#include <string>

static void runClient() {
  while (true) {
    std::string c;
    std::cin >> c;
    try {
      WSASession session;
      UDPSocket socket;
      char buffer[100];
      
      socket.sendTo("127.0.0.1", 100, c.c_str(), c.size());
      socket.recvFrom(buffer, 100);
      std::cout << buffer << std::endl;
    }
    catch (std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }
    if (c == "stop" || c == "exit") break;
  }
}

int main() {
  std::cout << "Client starting" << std::endl;
  runClient();
  std::cout << "Client shutting down" << std::endl;
  return 0;
}
