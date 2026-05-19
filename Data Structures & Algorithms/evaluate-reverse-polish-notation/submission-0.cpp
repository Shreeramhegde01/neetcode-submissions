class Solution {
    bool isN(const string& s) {
    try {
        stoi(s);
        return true;
    } catch (...) {
        return false;
    }
}
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string &s:tokens){
            if(isN(s)) st.push(s);
            else{
                int n1,n2;
                if(!st.empty())
                n1=stoi(st.top());
                st.pop();
                if(!st.empty())
                n2=stoi(st.top());
                st.pop();
                if(s=="+") n2+=n1;
                else if(s=="-") n2-=n1;
                else if(s=="*") n2*=n1;
                else if(n1!=0) n2/=n1;
                st.push(to_string(n2));
            }
        }
        return stoi(st.top());
    }
};
