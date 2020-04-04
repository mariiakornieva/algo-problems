/*
*   Move Zeroes
* 
*/

#include <vector>
#include <utility>
#include <iostream>

class Solution {
public:
    void moveZeroes(std::vector<int> const& nums) {
        for (int cur = 0, zero = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != 0) {
                std::swap(nums[zero++], nums[cur]);
            }
        }
    }
};