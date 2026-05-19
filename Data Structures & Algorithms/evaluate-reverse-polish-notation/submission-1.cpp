class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &s : tokens) {
            if (s == "+" || s == "-" ||
                s == "*" || s == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if (s == "+") st.push(n2 + n1);
                else if (s == "-") st.push(n2 - n1);
                else if (s == "*") st.push(n2 * n1);
                else st.push(n2 / n1);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};