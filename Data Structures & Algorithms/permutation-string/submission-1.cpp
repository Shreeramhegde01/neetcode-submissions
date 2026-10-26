class Solution {
    bool ck(vector<int> &a, vector<int> &b){
        for(int i=0;i<26;i++)if(a[i]!=b[i]) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> a(26,0),b(26,0);
        for(char &c:s1) a[c-'a']++;
        int i=0,j=0;
        while(j<s2.size()){
            b[s2[j]-'a']++;
            if(j-i+1>s1.size())b[s2[i++]-'a']--;
            if(j-i+1==s1.size() and ck(a,b)) return true;
           
            j++;
        }
        return false;
    }
};
