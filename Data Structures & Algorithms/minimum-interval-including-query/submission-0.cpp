class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        priority_queue<vector<int>> pq;
        unordered_map<int,int> mpp;
        vector<int> Q=q, ans;
        int i=0,n=in.size();
        sort(in.begin(),in.end());
        sort(Q.begin(),Q.end());
        for(int k:Q){
            while(i<n and in[i][0]<=k){
                int l=in[i][0],r=in[i++][1];
                pq.push({l-r-1,r});
            }
            while(pq.size() and pq.top()[1]<k) pq.pop();
            mpp[k]=pq.size()?-pq.top()[0]:-1;
        }
        for(int k:q){
            ans.push_back(mpp[k]);
        }
    return ans;
    }
};