class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto &i: strs){
            s+=to_string(i.size())+"!"+i;
        }
        return s;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size()){
            int j=i;
            while(s[j]!='!') j++;
            int len=stoi(s.substr(i,j-i));
            j++;
            string cur=s.substr(j,len);
            i=j+len;
            ans.push_back(cur);
        }
        return ans;
    }
};
