class Solution {
    int allStars(string& pat, int j, int m){
        while(j < m){
            if(pat[j] != '*')return 0;
            j ++;
        }
        return 1;
    }
    bool solve(int i, int j, int n, int m, string& txt, string& pat, 
    vector<vector<int>>& dp){
        if(i == n && j == m)return 1;
        if(i >= n)return allStars(pat, j, m) == 1;
        if(j == m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(txt[i] == pat[j] || pat[j] == '?'){
            return dp[i][j] = solve(i + 1, j + 1, n, m, txt, pat, dp);
        }
        if(pat[j] == '*'){
            return dp[i][j] = solve(i, j + 1, n, m, txt, pat, dp) ||
                                solve(i + 1, j, n, m, txt, pat, dp);
        }
        return dp[i][j] = 0;
    }
  public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, txt, pat, dp);
    }
};