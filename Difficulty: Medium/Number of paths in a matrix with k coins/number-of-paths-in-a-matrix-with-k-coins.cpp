class Solution {
    int solve(int i, int j, int n, int m, int k, vector<vector<int>>& mat, 
    vector<vector<vector<int>>>& dp){
        if(i == n - 1 && j == m - 1)return k == mat[i][j];
        if(i == n || j == m || k < 0)return 0;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int right = 0, down = 0;
        if(k - mat[i][j] >= 0){
            right = solve(i, j + 1, n, m, k - mat[i][j], mat, dp);
            down = solve(i + 1, j, n, m, k - mat[i][j], mat, dp);
        }
        return dp[i][j][k] = right + down;
    }
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(0, 0, n, m, k, mat, dp);
    }
};