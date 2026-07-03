class Solution {
public:
    int reverse(int x) {
       string s=to_string(x);
       std::reverse(s.begin(), s.end());
       long long t=0;
       bool neg=false;
       if(s.back()=='-') {s.pop_back(); neg=true;}
       t=stoll(s);
       if(neg) t*=-1;
       if(t>INT_MAX or t<INT_MIN) return 0;
       return t;
    }
};
