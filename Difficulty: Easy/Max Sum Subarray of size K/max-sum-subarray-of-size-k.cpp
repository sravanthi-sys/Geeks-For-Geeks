class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0, ans = arr[0];
        for(int i = 0, l = 0 ; i < n ; i ++){
            sum += arr[i];
            if(i >= k - 1){
                ans = max(ans, sum);
                sum -= arr[l];
                l ++;
            }
        }
        return ans;
    }
};