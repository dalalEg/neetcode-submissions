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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
int curr = 1;
while (temp->next != nullptr) {
    curr++;
    temp = temp->next;
}

// Do NOT make it circular yet
// temp->next = head; // <-- Remove or comment this

ListNode* temp2 = head;
int i = 0;
while (i < curr / 2) {
    temp2 = temp2->next;
    i++;
}

// Reverse second half
ListNode* prev = nullptr;
while (temp2 != nullptr) {
    ListNode* next = temp2->next;
    temp2->next = prev;
    prev = temp2;
    temp2 = next;
}
 ListNode* first = head;
        temp2 = prev;
        while (temp2 != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = temp2->next;
            first->next = temp2;
            temp2->next = tmp1;
            first = tmp1;
            temp2 = tmp2;
        }
        if (first != nullptr)
    first->next = nullptr;

    }
    
};

       
       
