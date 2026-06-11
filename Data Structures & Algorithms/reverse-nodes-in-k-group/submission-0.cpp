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
    ListNode* rev(ListNode* a){
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        ListNode* cur=a;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    ListNode* f(ListNode* a, int k){
        k--;
        ListNode* b=a;
        while(k>0 and b){
            b=b->next;
            k--;
        }
        return b;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next) return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* kth=f(temp,k);
            if(!kth){
                if(prev) prev->next=temp;break;
            }
            ListNode* nxt=kth->next;
            kth->next=nullptr;
            rev(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prev->next=kth;
            }
            prev=temp;
            temp=nxt;
        }
        return head;
    }
};
