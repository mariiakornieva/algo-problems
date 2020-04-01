/*
*   Single Number
* Given a non-empty array of integers, every element appears twice
* except for one. Find that single one.
* The algorithm should have a linear runtime complexity.Could you
* implement it without using extra memory?
*/
#include <vector>
#include <set>

class Solution {
public:
    int singleNumber(std::vector<int> const& nums) {
        std::set<int> s;
        for (auto elem : nums) {
            if (std::end(s) != s.find(elem)) {
                s.erase(elem);
            } else {
                s.insert(elem);
            }
        }
        return *s.begin();
    }
};

int main()
{
    Solution solution;
    solution.singleNumber({1,2,2,3,4,1,5,6,5,6});
}