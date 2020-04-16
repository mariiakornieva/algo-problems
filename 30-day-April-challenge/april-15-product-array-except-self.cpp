// Product of Array Except Self
// Given an array nums of n integers where n > 1, 
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

#include <vector>
#include <numeric>
#include <algorithm>

// Pre C++17 solution
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> const& nums) {
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

// Solution using C++ std::exclusive_scan
class Solution17 {
public:
    std::vector<int> productExceptSelf(std::vector<int> const& nums) {
        std::vector<int> pref(nums.size());
        std::vector<int> suf(nums.size());
        std::exclusive_scan(nums.begin(), nums.end(),
                            pref.begin(), 1,
                            std::multiplies<int>());
        std::exclusive_scan(nums.rbegin(), nums.rend(),
                            suf.rbegin(), 1,
                            std::multiplies<int>());
 
        std::vector<int> products(nums.size());
        std::transform(pref.begin(), pref.end(),
                       suf.begin(), products.begin(),
                       std::multiplies<int>());
    
        return products;
    }
};
