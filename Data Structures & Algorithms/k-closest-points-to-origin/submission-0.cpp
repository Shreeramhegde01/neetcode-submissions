class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        for(int i=0;i<points.size();i++){
            double dist=sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            auto [d,i]=pq.top();
            pq.pop();
            ans.push_back(points[i]);
        }
        return ans;
    }
};