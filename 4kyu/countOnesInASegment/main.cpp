#include <array>
#include <cmath>
#include <iostream>
#include <vector>

long long countBinaryOne(int n) {
  if (n == 0)
    return 0;
  int x = log2(n);
  return x * pow(2, (x - 1)) + n - pow(2, x) + 1 +
         countBinaryOne(n - pow(2, x));
}

long long countOnes(int left, int right) {
  return countBinaryOne(right) - countBinaryOne(left - 1);
}

using namespace std;

int main() { cout << countOnes(4, 7) << endl; }
