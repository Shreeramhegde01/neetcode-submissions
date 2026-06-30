class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n,0),next(n,0);
        cur[n-1]=next[n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1) continue;
                cur[j] = i<m-1?next[j]:0;
                cur[j]+= j<n-1?cur[j+1]:0;
            }
            next=cur;
        }
        return cur[0];
    }
};
