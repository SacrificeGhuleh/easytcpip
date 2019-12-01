//
// Created by zvone on 01-Dec-19.
//

#include <udpsocket.h>
#include <wsasession.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <system_error>

static void runServer() {
  try {
    WSASession Session;
    UDPSocket Socket;
    char buffer[100];
    
    Socket.Bind(100);
    while (true) {
      std::cout << "Waiting for packet..." << std::endl;
      sockaddr_in add = Socket.RecvFrom(buffer, sizeof(buffer));
      
      std::string input(buffer);
      if (input == "stop" || input == "exit") break;
      std::reverse(std::begin(input), std::end(input));
      Socket.SendTo(add, input.c_str(), input.size());
    }
  }
  catch (std::system_error &e) {
    std::cout << "Exception occured: ";
    std::cout << e.what() << std::endl;
  }
}

int main() {
  std::cout << "Server starting" << std::endl;
  runServer();
  std::cout << "Server shutting down" << std::endl;
  return 0;
}
