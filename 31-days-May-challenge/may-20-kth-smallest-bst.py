'''
  Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        tree_elem = []
        
        def inorder(root: TreeNode):
            if not root:
                return
            
            inorder(root.left)
            tree_elem.append(root.val)
            inorder(root.right)
            
        inorder(root)
        print(tree_elem)
        
        if k <= len(tree_elem):
            return tree_elem[k-1]
        else:
            return 0
