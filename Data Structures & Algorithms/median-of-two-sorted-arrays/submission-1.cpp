class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        int mid1=0,mid2=0;
        for(int count=0;count<(n1+n2)/2+1;count++){
            mid2=mid1;
            if(i<n1 and j<n2){
                if(nums1[i]<nums2[j]) mid1=nums1[i++];
                else mid1=nums2[j++];
            }
            else if(i<n1){
                mid1=nums1[i++];
            }
            else mid1=nums2[j++];
        }
        return (n1+n2)&1?mid1:(double)(mid1+mid2)/2;
    }
};
