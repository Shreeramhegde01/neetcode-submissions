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
    unordered_map<Node*, Node*> mpp;
public:
    Node* copyRandomList(Node* head) {
        Node* t=head;
        while(t){
            mpp[t]=new Node(t->val);
            t=t->next;
        }
        t=head;
        while(t){
            mpp[t]->next=t->next?mpp[t->next]:nullptr;
            mpp[t]->random=t->random?mpp[t->random]:nullptr;
            t=t->next;
        }
        return mpp[head];
    }
};
