'''
Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
'''

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        dp = []
        count = 0
        dp.append(matrix[0])
        for i in dp[0]:
            count += i
        
        for i in range(1, len(matrix)):
            dp.append([0 for _ in range(len(matrix[0]))])
            dp[i][0] = matrix[i][0]
            count += dp[i][0]

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 1:
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))
                count += dp[i][j]
        
        return count
