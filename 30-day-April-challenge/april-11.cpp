/*
*   Diameter of Binary Tree
*/


struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    int traverse(TreeNode* root, int& diam) {
        if (!root) return 0;

        int left = traverse(root->left, diam);
        int right = traverse(root->right, diam);
        diam = std::max(diam, left + right);
        
        return std::max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int diam = 0;
        traverse(root, diam);
        return diam;
    }
};
