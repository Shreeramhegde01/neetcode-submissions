class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0,rightmax=0,l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<leftmax) ans+=leftmax-height[l];
                else leftmax=height[l];
                l++;
            }
            else{
                if(height[r]<rightmax) ans+=rightmax-height[r];
                else rightmax=height[r];
                r--;
            }
        }
        return ans;
    }
};
