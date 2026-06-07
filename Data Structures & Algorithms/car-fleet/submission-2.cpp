class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int ans=0;
        double maxtime=0;
        for(auto &it:v){
            double time=(double)(target-it.first)/it.second;
            if(time>maxtime){
                ans++;
                maxtime=time;
            }
        }
        return ans;
    }
};
