#include <cstdint>
#include <iostream>

bool CompareStr(const char* x, const char* y) {
  while (*x != '\0' && *y != '\0' && *x == *y) {
    x++;
    y++;
  }
  return *x == '\0' && *y == '\0';
}

void Error() { std::cout << "error" << '\n'; }

bool Deposit(int64_t& money);
bool Withdrow(int64_t& money);
bool Balance(int64_t& money);
bool Reset(int64_t& money);
bool Stop(int64_t& money);
bool CanITakeADoner(int64_t& money);
int main() {
  int64_t money = 0;
  std::pair<const char*, bool (*)(int64_t&)> operations[]{
      {"deposit", Deposit},
      {"withdrow", Withdrow},
      {"balance", Balance},
      {"reset", Reset},
      {"stop", Stop},
      {"can-I-take-a-doner?", CanITakeADoner},  // могу ли купить шаурму
  };
  const size_t cn = 6;                // количество доступных команд
  const size_t ccommand_length = 20;  // максимальная длина команды

  while (true) {
    char current[ccommand_length]{};
    std::cin >> current;
    bool flag = false;
    for (size_t i = 0; i != cn; ++i) {
      if (CompareStr(current, operations[i].first)) {
        flag = (*operations[i].second)(money);
        break;
      }
    }
    if (!flag) {
      Error();
    }
  }

  return 0;
}

bool CanITakeADoner(int64_t& money) {
  const int64_t ccost = 400;
  if (money >= ccost) {
    std::cout << "Of course!" << '\n';
  } else {
    std::cout << "No(" << '\n';
  }
  return true;
}

bool Deposit(int64_t& money) {
  int64_t k{};
  std::cin >> k;
  if (k <= 0) {
    return false;
  }
  money += k;
  return true;
}

bool Withdrow(int64_t& money) {
  int64_t k{};
  std::cin >> k;
  if (k <= 0) {
    return false;
  }
  money -= k;
  return true;
}

bool Balance(int64_t& money) {
  std::cout << money << '\n';
  return true;
}

bool Reset(int64_t& money) {
  money = 0;
  return true;
}

bool Stop(int64_t& money) { std::exit(0); }
