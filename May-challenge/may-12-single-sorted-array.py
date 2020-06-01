'''
 Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once. Find this single element that appears only once.
'''

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l = 0
        r = len(nums)-1
        
        if r == 0:
            return nums[l]
        if r >= 1 and nums[l] != nums[l+1]:
            return nums[l]
        if r >= 1 and nums[r] != nums[r-1]:
            return nums[r]
        
        while l <= r:
            mid = (l+r)//2
            
            # if pair starting at even index - search in an opposite side of the array
            if mid > 0 and mid < len(nums):
                if nums[mid] == nums[mid+1]:
                    if mid % 2 != 0:
                        r = mid-1
                    else:
                        l = mid+1
                elif nums[mid-1]==nums[mid]:
                    if (mid-1) % 2 != 0:
                        r = mid-1
                    else:
                        l = mid+1
                else:
                    return nums[mid]
        return 0
                
        
        
