class Solution {
    void solve(int n, int k, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (k == 0) {
            if (n == 0) ans.push_back(path);
            return;
        }
        for (int i = start; i <= 9 && i <= n; i++) {
            path.push_back(i);
            solve(n - i, k - 1, i + 1, path, ans); 
            path.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(n, k, 1, path, ans);
        return ans;
    }
};