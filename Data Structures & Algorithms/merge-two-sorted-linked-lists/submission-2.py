# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        temp1,temp2=list1,list2
        dummy = node = ListNode()
        while list1 and list2:
            if list1.val > list2.val:
                node.next=list2
                list2=list2.next
            else:
                node.next=list1
                list1=list1.next
            node = node.next

        if list1:
            node.next = list1
        if list2:
            node.next=list2
        return dummy.next
        