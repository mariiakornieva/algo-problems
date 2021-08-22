#include <iostream>
#include <string>

void permutation(std::string const& str, std::string const& prefix) {
  if (str.empty()) {
    std::cout << prefix << "\n";
    return;
  }

  for (size_t i = 0; i < str.size(); ++i) {
    std::string rem = str.substr(0, i) + str.substr(i + 1);
    permutation(rem, prefix + str[i]);
  }
}

void permutation(std::string const &str) {
  permutation(str, "");
}

int main() {
  permutation("hello");
}
