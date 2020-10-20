#https://leetcode.com/problems/symmetric-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def ismirror(self,root1,root2):
        if root1==None and root2==None:
            return True
        if root1!=None and root2!=None:
            if root1.val==root2.val:
                return ((self.ismirror(root1.left,root2.right)) and (self.ismirror(root1.right,root2.left)))
        return False
    
    def isSymmetric(self, root: TreeNode) -> bool:
        if root==None:
            return True
        return self.ismirror(root,root)
        