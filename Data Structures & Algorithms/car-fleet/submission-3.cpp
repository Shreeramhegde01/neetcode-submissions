class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n=p.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({p[i],s[i]});
        sort(v.rbegin(),v.rend());
        int ans=0;
        double mxt=0;
        for(int i=0;i<n;i++){
            double cur=(double)(target-v[i].first)/v[i].second;
            if(cur>mxt){
                ans++;
                mxt=cur;
            }
        }
        return ans;
    }
};
