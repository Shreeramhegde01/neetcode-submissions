class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n=h.size();
        int ans=0;
        for(int i=0;i<=n;i++){
            while(st.size() and (i==n or h[st.top()]>=h[i])){
                int hg=h[st.top()];
                st.pop();
                int w = st.size()?i-st.top()-1:i;
                ans=max(ans,hg*w);
            }
            st.push(i);
        }
        return ans;
    }
};
