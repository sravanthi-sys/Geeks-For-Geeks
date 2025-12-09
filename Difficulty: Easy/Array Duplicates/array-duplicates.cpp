class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i = 0 ; i < arr.size() ; i ++)mpp[arr[i]] ++;
        for(auto it : mpp){
            if(it.second == 2)ans.push_back(it.first);
        }
        return ans;
    }
};