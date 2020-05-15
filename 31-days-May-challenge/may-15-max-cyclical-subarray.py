'''
Maximum Sum Circular Subarray
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.
(Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
'''

class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        min_sum = sys.maxsize
        max_sum = -sys.maxsize-1
        array_sum = 0
        temp_max = 0
        temp_min = 0
        
        for i in A:
            array_sum += i
            
            temp_max += i
            max_sum = temp_max if max_sum < temp_max else max_sum
            temp_max = 0 if temp_max < 0 else temp_max
            
            temp_min += i
            min_sum = temp_min if min_sum > temp_min else min_sum
            temp_min = 0 if temp_min > 0 else temp_min
            
        if array_sum == min_sum:
            return max_sum
        return max([max_sum, (array_sum-min_sum)])
