//   Given a non-empty binary tree, find the maximum path sum.
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the root.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxSum(TreeNode* root, int& result) {
        if (!root) return 0;
        
        int left = maxSum(root->left, result);
        int right = maxSum(root->right, result);
        
        int m = std::max(std::max(left, right)+root->val, root->val);
        int m2 = std::max(m, left+right+root->val);
        result = std::max(m2, result);
        return m;
    }

public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        
        int result = INT_MIN;
        maxSum(root, result);
        return result;
    }
};
