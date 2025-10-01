class Solution {
    void solve(int ind, int n, vector<int>& arr, vector<vector<int>>& ans){
        if(ind == n - 1){
            ans.push_back(arr);
            return ;
        }
        unordered_set<int> vis;
        for(int i = ind ; i < n ; i ++){
            if(vis.find(arr[i]) != vis.end())continue;
            vis.insert(arr[i]);
            swap(arr[i], arr[ind]);
            solve(ind + 1, n, arr, ans);
            swap(arr[i], arr[ind]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        solve(0, arr.size(), arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};