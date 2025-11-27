class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i ++)ans |= arr[i];
        return ans * (1 << (arr.size() - 1));
    }
};