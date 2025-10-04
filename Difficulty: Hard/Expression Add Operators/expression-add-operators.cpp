class Solution {
    vector<string> ans;
    bool eval(string expr, int target){
        long long num = 0;
        char op = '+';
        stack<long long> st;
        for (int i = 0; i < expr.size(); i++) {
            char c = expr[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) || i == expr.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    long long top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                op = c;   
                num = 0;  
            }
        }
        long long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result == target;
    }
    void solve(int ind, int n, int target, string curr, string& s){
        if (ind == n) {  
            if (eval(curr, target)) {
                ans.push_back(curr);
            }
            return;
        }
        for (int i = ind; i < n; i++) {
            if (i > ind && s[ind] == '0') break;
            string numStr = s.substr(ind, i - ind + 1);
            if (ind == 0) {
                solve(i + 1, n, target, curr + numStr, s);
            } else {
                solve(i + 1, n, target, curr + "+" + numStr, s);
                solve(i + 1, n, target, curr + "-" + numStr, s);
                solve(i + 1, n, target, curr + "*" + numStr, s);
            }
        }
    }
  public:
    vector<string> findExpr(string &s, int target) {
        solve(0, s.length(), target, "", s);
        return ans;
    }
};