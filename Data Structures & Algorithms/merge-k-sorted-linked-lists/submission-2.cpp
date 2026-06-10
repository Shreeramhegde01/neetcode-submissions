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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *d=new ListNode();
        ListNode *temp=d;
        while(list1 and list2){
            if(list1->val<list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1) temp->next=list1;
        if(list2) temp->next=list2;
        return d->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.empty())
            return nullptr;
        int interval = 1;
        while(interval < lists.size()){
            for(int i=0;i + interval < lists.size(); i += interval * 2){
                lists[i] =mergeTwoLists(lists[i],lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};
