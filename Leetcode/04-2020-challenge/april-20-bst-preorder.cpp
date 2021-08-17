// Construct Binary Search Tree from Preorder Traversal


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
    void insert(TreeNode* root, TreeNode* node) {
        if (node->val < root->val) {
            if (root->left) {
                insert(root->left, node);
            } else {
                root->left = node;
            }
        } else {
            if (root->right) {
                insert(root->right, node);
            } else {
                root->right = node;
            }
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for (int i = 1; i < preorder.size(); ++i) {
            auto node = new TreeNode(preorder[i]);
            insert(root, node);
        }
        
        return root;
    }
};
