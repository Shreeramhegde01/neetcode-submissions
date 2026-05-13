class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<char> st;
        int n=s.size();
        int l=0,r=1;
        int ans=1;
        st.insert(s[0]);
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r++]);
                ans=max(ans,r-l);
            }
            else{
                while(l<=r and st.find(s[r])!=st.end()){
                auto it=st.find(s[l++]);
                st.erase(it);
                }
            }
        }
        return ans;
    }
};
