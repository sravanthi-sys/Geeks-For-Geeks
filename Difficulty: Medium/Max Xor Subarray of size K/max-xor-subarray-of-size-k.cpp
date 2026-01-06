class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int ans = 0, xorr = 0;
        for(int i = 0, l = 0 ; i < arr.size() ; i ++){
            xorr ^= arr[i];
            if(i >= k - 1){
                ans = max(ans, xorr);
                xorr ^= arr[l];
                l ++;
            }
        }
        return ans;
    }
};