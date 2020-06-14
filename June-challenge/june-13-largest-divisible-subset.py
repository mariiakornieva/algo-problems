'''
  Largest Divisible Subset
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
'''

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        max = 1
        dp = [1 for _ in range(len(nums)+1)]
        for i in range(1, len(nums)):
            for j in range(0, i):
                if nums[i]%nums[j]==0 and 1+dp[j]>dp[i]:
                    dp[i] = 1+dp[j]
                    if max < dp[i]:
                        max = dp[i]
        prev = -1
        result = []
        for i in range(len(nums)-1, -1, -1):
            if dp[i] == max and (prev%nums[i]==0 or prev==-1):
                result.append(nums[i])
                max-=1
                prev=nums[i]
                
        return result
