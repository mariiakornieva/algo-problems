#include <iostream>
#include <vector>
#include <sstream>

int distance(std::vector<int> const& v) {
    int result = 0;

    std::vector<int> trashBins;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            trashBins.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            auto trash = std::lower_bound(trashBins.begin(), trashBins.end(), i);
            result += std::min((*trash) - i, i - (*(trash-1)));
        }
    }

    return result;
}

int main() {
    int N = 0;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        int size = 0;
        std::cin >> size;

        std::vector<int> v;

        std::string str;
        if (std::getline(std::cin, str)) {
          std::istringstream sstr(str);
          int n;
          while (sstr >> n) {
            v.push_back(n);
          }
        }

        for (auto e : v) {
            std::cout << e << " ";
        }
        std::cout << "\n";

        // std::cout << "Case #" << i << ": " << distance(v) << "\n";
    }

    return 0;
}
