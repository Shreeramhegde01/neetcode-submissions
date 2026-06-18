class Solution {
    bool ispal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void f(vector<vector<string>>& v, vector<string> &a, string s){
        if(s.size()==0){
            v.push_back(a);
            return;
        }
        for(int i=0;i<s.size();i++){
            string ss=s.substr(0,i+1);
            if(ispal(ss)){
                a.push_back(ss);
                f(v,a,s.substr(i+1));
                a.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> a;
        f(v,a,s);
        return v;
    }
};
