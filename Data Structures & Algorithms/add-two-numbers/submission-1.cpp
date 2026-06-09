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
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        while(t1 and t2){
            int t=carry+t1->val+t2->val;
            carry=t/10;
            t1->val=t%10;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            int t=t1->val+carry;
            carry=t/10;
            t1->val=t%10;
            t1=t1->next;
        }
        t1=l1;
        while(t1->next) t1=t1->next;
        t1->next=t2;
        while(t2){
            int t=t2->val+carry;
            carry=t/10;
            t2->val=t%10;
            t2=t2->next;
        }
        if(carry){
            t1=l1;
            while(t1->next) t1=t1->next;
            t1->next=new ListNode(carry);
        }
        return l1;
    }
};
