class LRUCache {   
public:
    class node{
        public:
        int key,value;
        node* next;
        node* prev;
        node(int k,int v){
            key=k;
            value=v;
        }
    };
    unordered_map<int,node*> mpp;
    int c;
    node *head= new node(-1,-1);
    node *tail= new node(-1,-1);
    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void add(node* a){
        node* t=head->next;
        head->next=a;
        a->next=t;
        a->prev=head;
        t->prev=a;
    }
    void del(node *a){
        node* p=a->prev;
        p->next=a->next;
        p->next->prev=p;
        
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* r=mpp[key];
            int v=r->value;
            del(r);
            add(r);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* r= mpp[key];
            mpp.erase(r->key);
            del(r);    
        }
        if(mpp.size()==c){
            mpp.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new node(key,value));
        mpp[key]=head->next;
    }
};
