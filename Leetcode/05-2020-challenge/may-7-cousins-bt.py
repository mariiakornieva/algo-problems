'''
  Cousins in Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def dfs(node, parent, depth, value):
            if not node:
                return False
            if node.val == value:
                return depth, parent
            return dfs(node.left, node, depth + 1, value) or dfs(node.right, node, depth + 1, value)
        dx, px = dfs(root, None, 0, x)
        dy, py = dfs(root, None, 0, y)
        
        return dx == dy and px != py
