/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    vector<int> arr;
    void solve(Node* root){
        if(root == NULL)return ;
        solve(root -> left);
        arr.push_back(root -> data);
        solve(root -> right);
    }
  public:
    int findMedian(Node* root) {
        // Code here
        solve(root);
        int n = arr.size();
        if(arr.size() % 2 == 0){
            return arr[n / 2 - 1];
        }
        return arr[n / 2];
        
    }
};