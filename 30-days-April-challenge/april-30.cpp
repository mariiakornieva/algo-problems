// Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

class Solution {
public:
    bool dfs(TreeNode* root, vector<int>& arr, int idx) {
        if (!root) return false;    

        if (idx < arr.size() && root->val != arr[idx]) return false;
        if (!root->left && !root->right && idx == arr.size() - 1) return true;

        return dfs(root->left, arr, idx + 1) || dfs(root->right, arr, idx + 1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
};
