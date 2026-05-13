class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n),right(n);
        int lm=0,rm=0;
        left[0]=right[n-1]=0;
        for(int i=1;i<n;i++){
            lm=max(lm,height[i-1]);
            left[i]=lm;
            rm=max(rm,height[n-i]);
            right[n-i-1]=rm;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};
