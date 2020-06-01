//    Jump Game
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
      int goodIdx = nums.size() - 1;
      
      for (int idx = nums.size() - 1; idx >= 0; --idx)
      {
        if (idx + nums[idx] >= goodIdx)
        {
          goodIdx = idx;
        }
      }
      return 0 == goodIdx;
    }
};
