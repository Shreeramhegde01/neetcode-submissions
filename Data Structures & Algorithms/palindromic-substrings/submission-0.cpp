class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int st=0,mx=1;
        auto ispal=[&](int l, int r){
            while(l>=0 and r<s.size() and s[l]==s[r]){
                ans++;
                l--,r++;
            }
        };
        for(int i=0;i<s.size();i++){
            ispal(i,i);
            ispal(i,i+1);
        }
        return ans;
    }
};