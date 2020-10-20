#https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1=''
        while l1!=None:
            num1+=str(l1.val)
            l1=l1.next
        num1=num1[::-1]
        num2=''
        while l2!=None:
            num2+=str(l2.val)
            l2=l2.next
        num2=num2[::-1]
        
        num3=str(int(num1)+int(num2))[::-1]
        l3=[int(i) for i in num3]
        ans=ListNode(l3[0])
        p=ans
        for i in range(1,len(l3)):
            p.next=ListNode(l3[i])
            p=p.next
        return ans
        