/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp=head;
        while (temp != nullptr){
            Node* temp2=new Node(temp->val);
            temp2->next=temp->next;
            temp->next=temp2;
            temp=temp2->next;
        }
        Node* newHead = head->next;
        temp=head;
        while (temp != nullptr){
            if (temp->random!=nullptr){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
      
         Node* l1 = head;
        while (l1 != nullptr) {
            Node* l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != nullptr) {
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }

        return newHead;
    }
};
