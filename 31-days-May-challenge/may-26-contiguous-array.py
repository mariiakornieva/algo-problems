'''
Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
'''

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = 0
        length = 0
        counts = {0: -1}
        
        for idx, elem in enumerate(nums):
            if elem == 1:
                count += 1
            else:
                count -= 1
                
            if count in counts:
                length = max(length, idx-counts[count])
            else:
                counts[count]=idx
                
        return length
