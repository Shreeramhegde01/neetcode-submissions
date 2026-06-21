class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses,0);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<ind.size();i++) if(ind[i]==0) q.push(i);
        int c=0;
        while(!q.empty()){
            c++;
            int it=q.front();
            q.pop();
            for(auto &i:adj[it]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
        }
        return c==numCourses;
    }
};
