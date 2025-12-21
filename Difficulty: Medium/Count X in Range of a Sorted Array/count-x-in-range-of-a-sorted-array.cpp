class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> ans;
        int n = ans.size();
        for(int q = 0 ; q < queries.size() ; q ++){
            int l = queries[q][0], r = queries[q][1], x = queries[q][2];
            int ub = upper_bound(arr.begin() + l, arr.begin() + r, x) - arr.begin();
            int lb = lower_bound(arr.begin() + l, arr.begin() + r, x) - arr.begin();
            // cout << q << " " << ub << " " << lb << endl;
            if(ub <= r && arr[ub] == x)
            ans.push_back(ub - lb + 1);
            else
            ans.push_back(ub - lb);
                
        }
        return ans;
    }
};