class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,-1);
        for(int i=0;i<s.size();i++) v[s[i]-'a']=i;
        int i=0;
        vector<int> ans;
        while(i<s.size()){
            int m=v[s[i]-'a'];
            int j;
            for(j=i;j<=m;j++){
                m=max(m,v[s[j]-'a']);
            }
            ans.push_back(m-i+1);
            i=j;
        }
        return ans;
    }
};
