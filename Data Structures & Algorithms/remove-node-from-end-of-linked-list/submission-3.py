# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy=ListNode(0,head)
        slow,fast=head,dummy
        while  n>0:
            slow=slow.next
            n=n-1
        while slow != None:
            slow=slow.next
            fast = fast.next
        fast.next=fast.next.next
        return dummy.next