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
        unordered_map<Node*, Node*> mp1,mp2;
        Node* temp=head;
        while(temp){
            mp1[temp]=temp->random;
            temp=temp->next;
        }
        Node* dummy = new Node(0);
        Node* t1=dummy;
        temp=head;
        while(temp){
            t1->next=new Node(temp->val);
            t1=t1->next;
            mp2[temp]=t1;
            temp=temp->next;
        }
        for(auto [a,b]: mp2){
            if(mp1[a]){
                b->random = mp2[mp1[a]];
            }
            else b->random=nullptr;
        }
        return dummy->next;
    }
};
