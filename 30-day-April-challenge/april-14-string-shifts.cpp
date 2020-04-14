// Perform String Shifts

class Solution {
public:
    std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
        int shiftCount = 0;
        for (int i = 0; i < shift.size(); ++i) {
            if (shift[i][0] == 0) {
                shiftCount -= shift[i][1];
            } else {
                shiftCount += shift[i][1];
            }
        }
        if (shiftCount != 0) {
            bool right = shiftCount > 0;
            shiftCount = std::abs(shiftCount);
            if (shiftCount > s.size()) {
                shiftCount = shiftCount % s.size();
            }
            if (right) {
                std::rotate(s.rbegin(), s.rbegin() + shiftCount, s.rend());
            } else {
                std::rotate(s.begin(), s.begin() + shiftCount, s.end());
            }
        }
        return s;
    }
};
