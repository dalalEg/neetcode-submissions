# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow,fast=head,head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        pre,curr=None,slow.next
        slow.next=None
        while curr:
            temp=curr.next
            curr.next=pre
            pre=curr
            curr=temp
        first,second=head,pre

        while second:
            temp1=first.next
            first.next=second
            temp2=second.next
            second.next=temp1
            first=temp1
            second = temp2

        