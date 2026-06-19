class Node{
public:
    Node* child[26];
    bool end;
    Node(){
        for(auto &a:child)a=nullptr;
        end=false;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* p=root;
        for(auto &c:word){
            if(!p->child[c-'a']) p->child[c-'a']=new Node();
            p=p->child[c-'a'];
        }
        p->end=true;
    }
    
    bool search(string word) {
        Node* p=root;
        for(auto &c:word){
            if(!p->child[c-'a']) return false;
            p=p->child[c-'a'];
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        Node* p=root;
        for(auto &c:prefix){
            if(!p->child[c-'a']) return false;
            p=p->child[c-'a'];
        }
        return true;
    }
};
