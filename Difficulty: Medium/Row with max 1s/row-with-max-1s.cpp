// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n=arr.size();
        int m=arr[0].size();
        int i=0,j=m-1;
        int ind=-1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                ind=i;
                j--;
            }
            else
            i++;
        }
        return ind;
    }
};
