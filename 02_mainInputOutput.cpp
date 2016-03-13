# include <iostream>

int main() {
  std::string name;
  std::cout << "Hello? My name is Computer." << std::endl;
  std::cout << "What's your name?" << std::endl;
  std::cin >> name;
  std::cout << "Hi! " << name << std::endl;
}
