#include <iostream>
#include <cstdint>
#include <cstring>
#include <limits>
#include <iomanip>

void Error() {
  std::cout << "error" << '\n';
}

bool Clear(char**& tablo, size_t cheight, size_t cwidth);
bool Put(char**& tablo, size_t cheight, size_t cwidth);
bool Text(char**& tablo, size_t cheight, size_t cwidth);
bool Print(char**& tablo, size_t cheight, size_t cwidth);
bool Quit(char**& tablo, size_t cheight, size_t cwidth);
int main() {
  const size_t cheight = 5;
  const size_t cwidth = 10;
  char** tablo = new char*[cheight];
  for (size_t i = 0; i != cheight; ++i) {
    tablo[i] = new char[cwidth + 1]{"          "};
  }

  using DifficultType = bool(*)(char**&, size_t, size_t);
  std::pair<const char*, DifficultType> operations[]{
    {"clear", Clear},
    {"put", Put},
    {"text", Text},
    {"print", Print},
    {"quit", Quit},
  };
  const size_t ccount_op = 5;
  const size_t ccommand_leng = 20;
  while (true) {
    bool flag = false;
    char current[ccommand_leng + 1];
    std::cin >> current;
    for (size_t i = 0; i != ccount_op; ++i) {
      if (std::strcmp(operations[i].first, current) == 0) {
        flag = (*operations[i].second)(tablo, cheight, cwidth);
        break;
      }
    }
    if (!flag) {
      Error();
    }
  }
  delete[] tablo;
  tablo = nullptr;
  return 0;
}

bool Clear(char**& tablo, size_t cheight, size_t cwidth) {
  for (size_t y = 0; y != cheight; ++y) {
    for (size_t x = 0; x != cwidth; ++x) {
      tablo[y][x] = ' ';
    }
  }
  return true;
}
bool IsOut(int32_t x, int32_t y, size_t cheight, size_t cwidth) {
  return (x < 0 || x >= cwidth || y < 0 || y >= cheight);
}

bool Put(char**& tablo, size_t cheight, size_t cwidth) {
  int32_t x;
  int32_t y;
  char c;
  std::cin >> x >> y >> c;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  bool is_out = IsOut(x, y, cheight, cwidth);
  if (is_out) {
    return false;
  }
  tablo[y][x] = c;
  return true;
}

bool Text(char**& tablo, size_t cheight, size_t cwidth) {
  int32_t x;
  int32_t y;
  const size_t cbuffer = 11;
  char current[cbuffer];
  std::cin >> x >> y >> std::setw(cbuffer) >> current;
  size_t leng = std::strlen(current);
  if (leng == 0) {
    return false;
  }
  bool is_out = IsOut(x + leng - 1, y, cheight, cwidth);
  if (is_out) {
    return false;
  }

  for (size_t i = 0; i != leng; ++ i) {
    tablo[y][x + i] = current[i];
  }
  return true;
}

bool Print(char**& tablo, size_t cheight, size_t cwidth) {
  for (size_t y = 0; y != cheight; ++y) {
    for (size_t x = 0; x != cwidth; ++x) {
      std::cout << tablo[y][x];
    }
    std::cout << '\n';
  }
  return true;
}

bool Quit(char**& tablo, size_t cheight, size_t cwidth) {
  std::exit(0);
}

