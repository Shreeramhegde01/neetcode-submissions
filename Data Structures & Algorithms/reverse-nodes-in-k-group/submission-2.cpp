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
    ListNode* rev(ListNode* head){
        ListNode* cur=head;
        ListNode* prev=nullptr;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    ListNode *kth(ListNode* t, int k){
        while(t and k>1){
            k--;
            t=t->next;
        }
        return t;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* kt=kth(temp,k);
            if(!kt){
                if(prev) prev->next=temp;
                break;
            }
            ListNode *nxt=kt->next;
            kt->next=nullptr;
            rev(temp);
            if(temp==head){
                head=kt;
            }
            else{
                prev->next=kt;
            }
            prev=temp;
            temp=nxt;
        }
        return head;

    }
};
