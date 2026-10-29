class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,h=m*n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target) return 1;
            else if(matrix[r][c]<target) l=mid+1;
            else h=mid-1;
        }
        return 0;
    }
};
