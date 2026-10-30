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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* sec=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(sec){
            ListNode* next=sec->next;
            sec->next=prev;
            prev=sec;
            sec=next;
        }
        sec=prev;
        ListNode* fir=head;
        while(sec){
            ListNode* t1=fir->next;
            ListNode* t2=sec->next;
            fir->next=sec;
            sec->next=t1;
            fir=t1;
            sec=t2;
        }
    }
};
