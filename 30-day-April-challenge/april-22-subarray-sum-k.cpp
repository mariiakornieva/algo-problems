//  Subarray Sum Equals K
// Given an array of integers and an integer k,
// you need to find the total number of continuous subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int prefix = 0;
            for (int j = i; j < nums.size(); ++j) {
                prefix += nums[j];
                if (prefix == k) ++count;
            }
        }
        
        return count;
    }
};
