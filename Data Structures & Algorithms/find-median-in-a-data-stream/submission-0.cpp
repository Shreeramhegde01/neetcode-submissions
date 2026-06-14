class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int,vector<int>, greater<int>> mn;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        mx.push(num);
        mn.push(mx.top());
        mx.pop();
        if(mn.size()>mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()>mn.size()) return mx.top();
        return (double)(mx.top()+mn.top())/2;
    }
};
