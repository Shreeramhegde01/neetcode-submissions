class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> ct,win;
        for(char &c:t) ct[c]++;
        int l=0;
        int stp=-1;
        int reslen=INT_MAX;
        int have=0, need=ct.size();
        for(int r=0;r<s.size();r++){
            char c=s[r];
            win[c]++;
            if(ct.count(c) and win[c]==ct[c]) have++;
            while(have==need){
                if(r-l+1<reslen){
                    reslen=r-l+1;
                    stp=l;
                }
                win[s[l]]--;
                if(ct.count(s[l]) and win[s[l]]<ct[s[l]]) have--;
                l++;
            }
        }
    return reslen==INT_MAX?"":s.substr(stp,reslen);
    }
};
