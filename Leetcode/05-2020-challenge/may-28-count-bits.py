'''
  Counting Bits
Given a non negative integer number num.
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation
and return them as an array.
'''

class Solution:
    def countBits(self, num: int) -> List[int]:
        result = [0 for _ in range(num+1)]
        for idx in range(num+1):
            result[idx] = result[idx//2] + idx%2
        return result
        
