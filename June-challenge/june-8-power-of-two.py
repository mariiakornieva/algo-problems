'''
   Power of Two
Given an integer, write a function to determine if it is a power of two.
'''

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        return floor(log2(n)) == ceil(log2(n))
