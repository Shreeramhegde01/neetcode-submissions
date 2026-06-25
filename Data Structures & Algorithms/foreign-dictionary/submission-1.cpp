class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> ind;
        for(auto &w:words){
            for(auto &c:w){
                adj[c]=unordered_set<char>();
                ind[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i],w2=words[i+1];
            int minlen=min(w1.length(),w2.length());
            if(w1.length()>w2.length() and w1.substr(0,minlen)==w2.substr(0,minlen)) return "";
            for(int j=0;j<minlen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        ind[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char>q;
        for(auto[ch,co]:ind){
            if(co==0) q.push(ch);
        }
        string res="";
        while(!q.empty()){
            char ch=q.front();
            q.pop();
            res+=ch;
            for(auto a:adj[ch]){
                ind[a]--;
                if(ind[a]==0) q.push(a);
            }
        }
        return res.size()==ind.size()?res:"";
    }
};
