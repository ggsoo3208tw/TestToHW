#include <string>//string must include
#include <iostream>// cout,endl must include

#include "terminal.h"

int main(int argc, char *argv[]){
  std::cout << "argv length => " << argc << std::endl;
  std::string input(argv[1]);
  std::string output(argv[2]);
  std::string featur(argv[3]);
  std::string order(argv[4]);
  std::cout << "input => " << input << std::endl;
  std::cout << "output => " << output << std::endl;
  std::cout << "featur => " << featur << std::endl;
  std::cout << "order => " << order << std::endl;
  return 0;
}
