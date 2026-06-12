class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int f=pq.top();
            pq.pop();
            int s=0;
            if(pq.size()) {s=pq.top();pq.pop();}
            pq.push(f-s);
        }
        return pq.top();
    }
};
