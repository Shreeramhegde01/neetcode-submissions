class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(char &c:s){
            if(isalnum(c)){c=tolower(c); t+=c;}
        }

        int l=0,h=t.size()-1;
        while(l<h){
            if(t[l++]!=t[h--]) return false;
        }
    return true;
    }
};
