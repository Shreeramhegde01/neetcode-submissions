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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1;
        ListNode* t2=l2;
        int c=0,s=0;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(t1 or t2){
            s=c;
            if(t1) s+=t1->val;
            if(t2) s+=t2->val;
            temp->next=new ListNode(s%10);
            c=s/10;
            temp=temp->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(c) temp->next=new ListNode(c);
        return dummy->next;
    }
};
