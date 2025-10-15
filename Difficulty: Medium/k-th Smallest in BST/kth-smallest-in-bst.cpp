/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    int ans ;
    void solve(Node *root, int& k){
        if(root == NULL || ans != -1)return ;
        solve(root -> left, k);
        k --;
        if(k == 0)ans = root -> data;
        solve(root -> right, k);
    }
  public:
    int kthSmallest(Node *root, int k) {
        ans = -1;
        solve(root, k);
        return ans;
    }
};