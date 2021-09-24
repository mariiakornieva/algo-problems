#include <iostream>
#include <vector>

void insert(std::vector<int> &v, int i) {
  while (i > 0 && v[i] < v[i-1]) {
    auto tmp = v[i];
    v[i] = v[i-1];
    v[i-1] = tmp;
    i--;
  }
}

int main() {
  std::vector<int> v{4, 3, 2, 1};
  
  for (size_t i = 0; i < v.size(); i++) {
    insert(v, i); 
  }
  
  for (auto const i : v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
  
  return 0;
}

