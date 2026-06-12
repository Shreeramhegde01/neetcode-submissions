class KthLargest {
    priority_queue<int, vector<int>,greater<int>> pq;
    int kt;
public:
    KthLargest(int k, vector<int>& nums) {
        kt=k;
        for(int &i:nums){
            if(pq.size()<k) pq.push(i);
            else if(pq.top()<i){
                pq.pop();
                pq.push(i);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()==kt){
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
                return pq.top();
            }
        }
        else if(pq.size()<kt){
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */