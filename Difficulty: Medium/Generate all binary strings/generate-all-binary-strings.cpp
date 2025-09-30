class Solution {
    void solve(int i, int n, string curr, vector<string>& ans){
        if(i == n){
            ans.push_back(curr);
            return ;
        }
        solve(i + 1, n, curr + '0', ans);
        solve(i + 1, n, curr + '1', ans);
    }
  public:
    vector<string> binstr(int n) {
        vector<string> ans;
        solve(0, n, "", ans);
        return ans;
    }
};