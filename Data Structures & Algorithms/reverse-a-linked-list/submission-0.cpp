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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* t1=head;
        ListNode* t2=head->next;
        ListNode* prev=nullptr;
        while(t2){
            t1->next=prev;
            prev=t1;
            t1=t2;
            t2=t2->next;
        }
        t1->next=prev;
        return t1;
    }
};
