#https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def arr_to_bst(self,arr):
        if len(arr)==0:
            return None
        mid=len(arr)//2
        root=TreeNode(arr[mid])
        root.left=self.arr_to_bst(arr[:mid])
        root.right=self.arr_to_bst(arr[mid+1:])
        return root
    
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if head==None:
            return None
        arr=[]
        while head:
            arr.append(head.val)
            head=head.next
        return self.arr_to_bst(arr)
        