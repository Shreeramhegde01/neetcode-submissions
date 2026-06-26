class Solution {
public:
    string longestPalindrome(string s) {
        int mxln=1;
        int start=0;
        auto pal=[&](int i,int j){
            while(i>=0 and j<s.size() and s[i]==s[j]){
                if(j-i+1>mxln){
                    mxln=j-i+1;
                    start=i;
                }
                i--;
                j++;
            }
        };
        for(int i=0;i<s.size();i++){
            pal(i,i);
            pal(i,i+1);
        }
        return s.substr(start,mxln);
    }
};
