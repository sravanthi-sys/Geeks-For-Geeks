/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void solve(Node* root, vector<int>& ans){
        if(root == NULL)return ;
        solve(root -> left, ans);
        solve(root -> right, ans);
        ans.push_back(root -> data);
    }
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};