class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int ans=0;
        int arr[26]={0};
        int freq=0;
        while(j<s.size()){
            freq=max(freq,++arr[s[j]-'A']);
            if(j-i+1-freq>k){
                arr[s[i++]-'A']--;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
