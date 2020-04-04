/*
*   Move Zeroes
* Given an array nums, write a function to move all 0's
* to the end of it while maintaining the relative order
* of the non-zero elements.
* 
* You must do this in-place without making a copy of the array.
* Minimize the total number of operations.
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