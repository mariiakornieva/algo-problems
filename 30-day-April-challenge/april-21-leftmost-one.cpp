//   Leftmost Column with at Least a One
// Interactive problem

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
private:
    int minPerRow(BinaryMatrix& bm, int row, int cols) {
        // Binary Search
        int l = 0;
        int h = cols-1;
        
        int col = INT_MAX;
        while (l <= h) {
            int mid = (l+h)>>1;
            int value = bm.get(row, mid);
            if (value == 1) {
                h = mid-1;
                col = mid;
            } else if (value == 0) {
                l = mid + 1;
            }
        }
        
        return col;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto const dim = binaryMatrix.dimensions();
        int const rows = dim[0];
        int const cols = dim[1];
        
        int col = INT_MAX;
        for (int i = 0; i < rows; ++i) {
            col = std::min(col, minPerRow(binaryMatrix, i, cols));
        }
        return col == INT_MAX ? -1 : col;
    }
};
