class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int const rows = grid.size();
        int const cols = grid[rows-1].size();
        
        auto accum = grid;
        // DP
        for (int i = 1; i < cols; ++i) {
            accum[0][i] += accum[0][i-1];
        }
        for (int i = 1; i < rows; ++i) {
            accum[i][0] += accum[i-1][0];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                accum[i][j] += std::min(accum[i-1][j], accum[i][j-1]);
            }
        }
        
        return accum[rows-1][cols-1];
    }
};
