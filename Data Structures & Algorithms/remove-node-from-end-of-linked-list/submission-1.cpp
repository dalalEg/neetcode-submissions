/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        int curr = 0;
        while (slow != nullptr) {
            slow = slow->next;
            curr++;
        }
        int skip = curr - n;
        if (skip == 0)
            return head->next;
        slow = head;
        while (skip > 1) {
            skip--;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
