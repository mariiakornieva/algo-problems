'''
Invert a binary tree.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return
            left = dfs(root.left)
            right = dfs(root.right)
            root.left = right
            root.right = left
            return root
            
        return dfs(root)
