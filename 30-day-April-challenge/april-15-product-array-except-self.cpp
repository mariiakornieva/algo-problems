// Product of Array Except Self
// Given an array nums of n integers where n > 1, 
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Pre C++17 solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> products;
        std::vector<int> pref{1};
        std::vector<int> suf{1};
        // exclusive_scan
        for (int i = 1, j = nums.size() - 2; i < nums.size() || j >= 0; ++i, --j) {
            pref.push_back(pref[i-1] * nums[i-1]);
            suf.push_back(suf[i-1] * nums[j+1]);
        }

        const int n = suf.size();
        for (int i = 0; i < pref.size(); ++i) {
            products.push_back(pref[i] * suf[n-1-i]);
        }
        
        return products;
    }
};
