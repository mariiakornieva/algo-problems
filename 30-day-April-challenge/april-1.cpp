/*
*   Single Number
* Given a non-empty array of integers, every element appears twice
* except for one. Find that single one.
* The algorithm should have a linear runtime complexity.Could you
* implement it without using extra memory?
*/
#include <vector>
#include <set>

class SolutionLinearSpace {
public:
    int singleNumber(std::vector<int> const& nums) {
        std::set<int> s;
        for (auto number : nums) {
            if (std::end(s) != s.find(number)) {
                s.erase(number);
            } else {
                s.insert(number);
            }
        }
        return *s.begin();
    }
};

class SolutionConstantSpace {
public:
    // 1^1 == 0
    // 1^0 == 1
    // 5^2^5 == 5^5^2 == 0^2 == 2
    int singleNumber(std::vector<int> const& nums) {
        int single = 0;
        for (auto number : nums) {
            single ^= number;
        }
        return single;
    }
};

int main()
{
    Solution solution;
    solution.singleNumber({1,2,2,3,4,1,5,6,5,6});
}