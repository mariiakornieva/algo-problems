/*
*   Diameter of Binary Tree
*/

#include <utility>


struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    std::pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        // pair{diameter, depth};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int diam = std::max({left.first, right.first,
                            left.second + right.second});
        return {diam, std::max(left.second, right.second) + 1};
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        return dfs(root).first;
    }
};
