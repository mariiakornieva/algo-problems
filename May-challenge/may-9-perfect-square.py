'''
Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
'''

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        # binary search
        left = 0
        right = num
        while left <= right:
            mid = (left + right)//2
            mid_sq = mid**2
            # print(f'{mid} sq = {mid_sq}')
            if mid_sq == num:
                return True
            elif mid_sq < num:
                left = mid+1
            elif mid_sq > num:
                right = mid-1
        return False
