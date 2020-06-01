'''
  Majority Element
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
'''

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Boyer-Moore Voting Algorithm
        count = 0
        majority = None
        
        for n in nums:
            if count == 0:
                majority = n
            count += 1 if n == majority else -1
            
        return majority
