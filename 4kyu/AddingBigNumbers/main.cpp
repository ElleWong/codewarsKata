#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
std::string add(const std::string &a, const std::string &b) {
  std::string newA = string(max(a.size(), b.size()) + 1 - a.size(), '0') + a;
  std::string newB = string(newA.size() - b.size(), '0') + b;
  for (int i = newA.size() - 1, carry = 0; i >= 0; i--) {
    int sum = newA[i] + newB[i] - 96 + carry;
    carry = sum / 10;
    newA[i] = sum % 10 + '0';
  }
  int i = newA.find_first_not_of('0');
  return i >= 0 ? newA.substr(i) : newA.substr(0, 1);
}

int main() {
  std::cout << add("335", "690") << "\n";
  return 0;
}
