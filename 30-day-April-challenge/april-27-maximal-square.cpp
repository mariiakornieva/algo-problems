//   Maximal Square
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        std::vector<std::vector<int>> dp(matrix.size()+1, std::vector(matrix[0].size()+1, 0));
        
        int result = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    result = std::max(dp[i][j], result);
                }
            }
        }
        
        return result*result;
    }
};
