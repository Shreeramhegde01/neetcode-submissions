class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> ct,win;
        for(char &c:t) ct[c]++;
        int l=0,strt=-1,rsl=INT_MAX,have=0,need=ct.size();
        for(int r=0;r<s.size();r++){
            char c=s[r];
            win[c]++;
            if(win[c]==ct[c]) have++;
            while(have == need){
                if(r-l+1<rsl){
                    rsl=r-l+1;
                    strt=l;
                }
                win[s[l]]--;
                if(ct.count(s[l]) and win[s[l]]<ct[s[l]]) have--;
                l++;
            }
        } 
        return rsl==INT_MAX?"":s.substr(strt,rsl);
    }
};
