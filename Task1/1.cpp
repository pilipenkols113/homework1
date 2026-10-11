#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>

double Average(const int32_t* temp, size_t n);
int32_t Min(const int32_t* temp, size_t n);
int32_t Max(const int32_t* temp, size_t n);
int32_t UnderZero(const int32_t* temp, size_t n);
int main() {
  size_t n;
  std::cin >> n;
  int32_t* temp = new int32_t[n];
  for (size_t i = 0; i != n; ++i) {
    std::cin >> temp[i];
  }

  double average = Average(temp, n);
  int32_t min = Min(temp, n);
  int32_t max = Max(temp, n);
  size_t under_zero = UnderZero(temp, n);

  std::cout << std::fixed << std::setprecision(1);
  std::cout << average << '\n';
  std::cout << min << ' ' << max << '\n';
  std::cout << under_zero << '\n';

  delete[] temp;
  temp = nullptr;
  return 0;
}

double Average(const int32_t* temp, size_t n) {
  int64_t sum = 0;
  for (size_t i = 0; i != n; ++i) {
    sum += temp[i];
  }
  return static_cast<double>(sum) / static_cast<double>(n);
}
int32_t Min(const int32_t* temp, size_t n) {
  const int32_t cinf = 1000;
  int32_t min = cinf;
  for (size_t i = 0; i != n; ++i) {
    min = std::min(min, temp[i]);
  }
  return min;
}
int32_t Max(const int32_t* temp, size_t n) {
  const int32_t cminus_inf = -1000;
  int32_t max = cminus_inf;
  for (size_t i = 0; i != n; ++i) {
    max = std::max(max, temp[i]);
  }
  return max;
}
int32_t UnderZero(const int32_t* temp, size_t n) {
  size_t count = 0;
  for (size_t i = 0; i != n; ++i) {
    if (temp[i] < 0) {
      count++;
    }
  }
  return count;
}
