class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for(int i = 0 ; i < n ; i ++){
            long long freq = 1LL * (i + 1) * (n - i);
            if(freq % 2 == 1){
                ans = ans ^ arr[i];
            }
        }
        return ans;
    }
};