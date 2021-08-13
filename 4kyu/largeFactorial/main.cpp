#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

std::string factorial(int n) {
  if (n < 0)
    return "";

  std::vector<int> resultVec{1};
  int remain{0};

  for (auto i = 2; i <= n; ++i) {
    for (size_t j = 0; j < resultVec.size(); ++j) {
      int result = i * resultVec[j] + remain;
      resultVec[j] = result % 10;
      remain = result / 10;
    }
    while (remain) {
      resultVec.push_back(remain % 10);
      remain /= 10;
    }
  }

  std::ostringstream ss;
  std::copy(std::rbegin(resultVec), std::rend(resultVec),
            std::ostream_iterator<int>(ss, ""));

  return ss.str();
}

int main(int argc, char *argv[]) { std::cout << factorial(25) << '\n'; }
