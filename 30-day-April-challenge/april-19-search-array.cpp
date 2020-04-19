// Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        
        while (l <= h) {
            if (nums[l] == target) return l;
            if (nums[h] == target) return h;

            int mid = (l+h)>>1;
            if (nums[mid] == target) return mid;
            
            if (target < nums[mid]) {
                if (nums[h] < nums[mid] && nums[h] >= target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            } else {
                if (nums[l] > nums[mid] && nums[l] <= target) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        
        return -1;
    }
};
