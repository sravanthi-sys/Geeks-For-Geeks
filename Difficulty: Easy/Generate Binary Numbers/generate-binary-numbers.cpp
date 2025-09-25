class Solution {
    string toBinary(int n){
      string ans="";
      int store;
      int cnt=0;
      while(n>0){
          ans=char((n%2)+'0')+ans;
          n=n/2;
      }
      return ans;
    }
  public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            res.push_back(toBinary(i));
        }
        return res;
    }
};