class Solution {
    void f(vector<int>& c, int t, int i, vector<vector<int>>& v, vector<int>&s){
        if(t==0){
            v.push_back(s);
            return;
        }
        for(int st=i;st<c.size();st++){
            if(st>i and c[st]==c[st-1]) continue;
            if(t<c[st]) break;
            s.push_back(c[st]);
            f(c,t-c[st],st+1,v,s);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> v;
        vector<int> s;
        sort(c.begin(),c.end());
        f(c,target,0,v,s);
        return v;
    }
};
