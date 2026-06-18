class Solution {
    void f(vector<string> &ans, int n, string s,int oc, int cc){
        if(oc==cc and s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(oc<n) f(ans,n,s+'(',oc+1,cc);
        if(cc<oc) f(ans,n,s+')',oc,cc+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(ans,n,"",0,0);
        return ans;
    }
};
