class Node{
    public:
    Node* child[26];
    bool end;
    Node(){
    for(auto &a:child) a=nullptr;
    end=false;
    }
};
class WordDictionary {
    Node* root;
    bool dfs(string &word,int idx,Node* node){
        if(!node)
            return false;
        if(idx==word.size())
            return node->end;
        if(word[idx]=='.'){
            for(int i=0;i<26;i++){
                if(node->child[i] &&
                   dfs(word,idx+1,node->child[i]))
                    return true;
            }
            return false;
        }
        return dfs(
            word,
            idx+1,
            node->child[word[idx]-'a']
        );
    }
public:
    WordDictionary() {
        root = new Node();
    }
    void addWord(string word) {
        Node* p = root;
        for(char c : word){
            int idx = c-'a';
            if(!p->child[idx])
                p->child[idx]=new Node();
            p=p->child[idx];
        }
        p->end=true;
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */