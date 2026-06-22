class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto[str,len]=q.front();
            q.pop();
            if(str==endWord) return len;
            for(int i=0;i<str.length();i++){
                char org=str[i];
                for(char j='a';j<='z';j++){
                    str[i]=j;
                    if(st.find(str)!=st.end()) {
                        q.push({str,len+1});
                        st.erase(str);
                    }
                }
                str[i]=org;
            }
        }
        return 0;
    }
};
