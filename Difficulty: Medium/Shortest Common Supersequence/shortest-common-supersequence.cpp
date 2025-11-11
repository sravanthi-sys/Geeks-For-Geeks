class Solution {
    int solve(int i, int j, int n, int m, string& s, string& t, vector<vector<int>>& dp){
        if(i == n || j == m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j])return dp[i][j] = 1 + solve(i + 1, j + 1, n, m, s, t, dp);
        return dp[i][j] = max(solve(i + 1, j, n, m, s, t, dp),
                                solve(i, j + 1, n, m, s, t, dp));
    }
  public:
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lcs = solve(0, 0, n, m, s1, s2, dp);
        return n + m - lcs;
    }
};