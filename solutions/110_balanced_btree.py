#https://leetcode.com/problems/balanced-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def ht(self,root):
        if root==None:
            return 0
        l=self.ht(root.left)
        r=self.ht(root.right)
        return max(l,r)+1
    
    def isBalanced(self, root: TreeNode) -> bool:
        if root==None:
            return True
        if root.left==None and root.right==None:
            return True
        l=self.ht(root.left)
        r=self.ht(root.right)
        if abs(l-r)<=1 and self.isBalanced(root.left) and self.isBalanced(root.right):
            return True
        else:
            return False
        