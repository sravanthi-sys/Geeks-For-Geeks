class Solution {
    int count(string& s ,int k){
        int ans = 0 ,cnt = 0;
        vector<int> mpp(26 ,0);
        for(int i = 0 ,l = 0; i < s.length() ;i++){
            if(mpp[s[i] - 'a'] == 0)cnt ++;
            mpp[s[i] - 'a'] ++;
            while(l <= i && cnt > k){
                mpp[s[l] - 'a'] --;
                if(mpp[s[l] - 'a'] == 0)cnt --;
                l ++;
            }
            ans += (i - l + 1);
        }
        return ans;
    }
  public:
    int countSubstr(string& s, int k) {
        return count(s ,k) - count(s ,k - 1);
    }
};