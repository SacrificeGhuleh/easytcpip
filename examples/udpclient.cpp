//
// Created by zvone on 01-Dec-19.
//
#include <udpsocket.h>

#include <exception>
#include <iostream>
#include <string>

static void runClient() {
  while (true) {
    std::string c;
    std::cin >> c;
    try {
      UDPSocket socket;
      socket.setOptReadTimeout(5000);
      char buffer[100];
      
      /*
      sockaddr_in add;
      add.sin_family = AF_INET;
      add.sin_addr.s_addr = ::htonl(INADDR_BROADCAST);
      add.sin_port = ::htons(100);*/


//      socket.sendto(add, c.c_str(), c.size());
      socket.sendto("127.0.0.1", 100, c.c_str(), c.size());
      if (c == "stop" || c == "exit") break;
      
      socket.recvfrom(buffer, 100);
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
