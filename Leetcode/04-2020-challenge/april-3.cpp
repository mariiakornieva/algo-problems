/*
*    Max Subarray
* Given an integer array nums, find the contiguous subarray
* (containing at least one number) which has the largest sum
* and return its sum.
* 
* If you have figured out the O(n) solution, try coding
* another solution using the divide and conquer approach,
* which is more subtle.
*/


#include <vector>
#include <iostream>

// Kadane's algorithm
class SolutionIterative {
public:
    int maxSubArray(std::vector<int> const& nums) {
        if (nums.empty()) return 0;
        
        int curMax = nums[0];
        int max = curMax;

        for (size_t i = 1; i < nums.size(); ++i) {
            curMax = std::max(nums[i] + curMax, nums[i]);
            if (curMax > max) {
                max = curMax;
            }
        }
        return max;
    }
};

class SolutionRecursive {
    private:
    int maxSubarraySum(std::vector<int> const& nums, int i, int& maxSum) {
        if (i == 0) return std::max(nums[i], maxSum);

        int newMax = std::max(nums[i], maxSubarraySum(nums, i-1, maxSum) + nums[i]);
        maxSum = std::max(newMax, maxSum);
 
        return newMax;
    }
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxSum = nums[0];
        maxSubarraySum(nums, nums.size() - 1, maxSum);
        return maxSum;
    }
};

// Divide and Conquer
class Solution {
public:
    int maxSubArray(std::vector<int> const& nums) {
        if (nums.size() == 1) return nums[0];

        int left = std::numeric_limits<int>::min();
        int const mid = (nums.size() - 1) / 2;
        int sum = 0;
        for (int i = mid; i >= 0; --i) {
            sum += nums[i];
            left = std::max(left, sum);
        }
        sum = 0;
        int right = std::numeric_limits<int>::min();
        for (int i = mid + 1; i < nums.size(); ++i) {
            sum += nums[i];
            right = std::max(right, sum);
        }

        return std::max({maxSubArray({nums.cbegin(), nums.cbegin() + mid + 1}),
                         maxSubArray({nums.cbegin() + mid + 1, nums.cend()}),
                         left + right});
    }
};

int main() {
    Solution sol;
    std::vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    std::cout << sol.maxSubArray(v) << "\n";
}
