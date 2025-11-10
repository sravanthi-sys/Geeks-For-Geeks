class Solution {
    int solve(int ind, int buy, int n, vector<int>& arr, vector<vector<int>>& dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind][buy] != -1)return dp[ind][buy];
        if(buy == 0){
            dp[ind][buy] = max(-arr[ind] + solve(ind + 1, 1, n, arr, dp),
                                        solve(ind + 1, 0, n, arr, dp));
        }
        else{
            dp[ind][buy] = max(arr[ind] + solve(ind + 2, 0, n, arr, dp),
                                        solve(ind + 1, 1, n, arr, dp));
        }
        return dp[ind][buy];
    }
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, n, arr, dp);
    }
};