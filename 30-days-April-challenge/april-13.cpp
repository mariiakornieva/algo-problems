// Contiguous Array
// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
// Input: [0,1]
// Output: 2
// Input: [0,1,0,0,0,1,1,0]
// Output: 6

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int len = 0;
        // (count, index)
        std::map<int, int> counts = {{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) ++count;
            else --count;
            
            if (counts.find(count) != std::end(counts)) {
                len = std::max(len, i-counts[count]);
            } else {
                counts[count] = i;
            }
        }
        
        return len;
    }
};
