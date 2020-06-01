'''
Construct Binary Search Tree from Preorder Traversal
Return the root node of a binary search tree that matches the given preorder traversal.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])
        
        def insert(root: TreeNode, node: TreeNode):
            if node.val < root.val:
                if root.left:
                    insert(root.left, node)
                else:
                    root.left = node
            else:
                if root.right:
                    insert(root.right, node)
                else:
                    root.right = node
        
        for elem in preorder[1:]:
            insert(root, TreeNode(elem))
        return root
