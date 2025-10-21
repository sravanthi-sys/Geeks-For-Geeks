class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> mpp;
        for(int i : arr)mpp[i] ++;
        vector<int> ans, uniq;
        for(auto it : mpp){
            uniq.push_back(it.first);
        }
        sort(uniq.begin(), uniq.end(), [&](int a, int b){
            if(mpp[a] != mpp[b]) return mpp[a] > mpp[b];
            return a > b;
        });
        int i = 0;
        while(k -- && i < uniq.size()){
            ans.push_back(uniq[i]);
            i ++;
        }
        return ans;
    }
};
