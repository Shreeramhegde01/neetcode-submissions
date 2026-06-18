class Solution {
    unordered_map<char,string> mpp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void f(string &s, int i, string res, vector<string>& ans){
        if(i==s.size()){ans.push_back(res);return;}
        string t=mpp[s[i]];
        for(char &c:t){
            f(s,i+1,res+c,ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) return ans;
        f(digits,0,"",ans);
        return ans;
    }
};
