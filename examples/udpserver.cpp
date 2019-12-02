//
// Created by zvone on 01-Dec-19.
//
#include <udpsocket.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <system_error>

static void runServer() {
  try {
    //WSASession wsaSession;
    UDPSocket socket;
    char buffer[100];
  
    socket.bind(100);
    while (true) {
      std::cout << "Waiting for packet..." << std::endl;
      sockaddr_in add = socket.recvfrom(buffer, sizeof(buffer));
      
      std::string input(buffer);
      if (input == "stop" || input == "exit") break;
      std::reverse(std::begin(input), std::end(input));
      socket.sendto(add, input.c_str(), input.size());
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
