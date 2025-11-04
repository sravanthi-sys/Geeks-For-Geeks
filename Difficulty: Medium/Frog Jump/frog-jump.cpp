class Solution {
    int solve(int ind, int n, vector<int>& heights, vector<int>& dp){
        if(ind == n - 1)return 0;
        if(dp[ind] != -1)return dp[ind];
        int ones = INT_MAX, twos = INT_MAX;
        if(ind + 1 < n)
        ones = abs(heights[ind + 1] - heights[ind]) + solve(ind + 1, n, heights, dp);
        if(ind + 2 < n)
        twos = abs(heights[ind + 2] - heights[ind]) + solve(ind + 2, n, heights, dp);
        return dp[ind] = min(ones, twos);
    }
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(0, n, height, dp);
    }
};