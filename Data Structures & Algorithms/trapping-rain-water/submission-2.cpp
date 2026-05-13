class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lm=0,rm=0;
        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<lm) ans+=lm-height[l];
                else lm=height[l];
                l++;
            }
            else{
                if(height[r]<rm) ans+=rm-height[r];
                else rm=height[r];
                r--;
            }
        }
        
        return ans;
    }
};
