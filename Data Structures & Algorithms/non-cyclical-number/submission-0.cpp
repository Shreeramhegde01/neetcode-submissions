class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(1){
            int t=0;
            while(n){
                t=t+((n%10)*(n%10));
                n/=10;
            }
            if(t==1) return true;
            if(st.find(t)!=st.end()) return false;
            st.insert(t); 
            n=t;
        }
        return false;
    }
};