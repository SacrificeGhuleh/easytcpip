//
// Created by zvone on 01-Dec-19.
//
#include <udpsocket.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <system_error>
#include <ws2tcpip.h>

static std::string ipv4_int_to_string(uint32_t in, bool *const success = nullptr) {
  std::string ret(INET_ADDRSTRLEN, '\0');
  in = htonl(in);
  const bool _success = (NULL != inet_ntop(AF_INET, &in, &ret[0], ret.size()));
  if (success) {
    *success = _success;
  }
  if (_success) {
    ret.pop_back(); // remove null-terminator required by inet_ntop
  } else if (!success) {
    char buf[200] = {0};
    throw std::runtime_error(
        std::string("error converting ipv4 int to string ") + std::to_string(errno) + std::string(": ") +
        std::string(buf));
  }
  return ret;
}

static void runServer() {
  try {
    UDPSocket socket;
    char buffer[100];
    
    socket.bind(100);
    while (true) {
      std::cout << "Waiting for packet..." << std::endl;
      sockaddr_in add = socket.recvfrom(buffer, sizeof(buffer));
      
      std::cout << "Received from " << ipv4_int_to_string(add.sin_addr.S_un.S_addr, nullptr) << std::endl;
      std::cout << "\tData " << buffer << std::endl;
      
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
