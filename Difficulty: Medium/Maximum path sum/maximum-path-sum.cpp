// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    int maxi = INT_MIN;
    int solve(Node *root){
        if(root == NULL)return 0;
        int rightMax = max(solve(root->right) ,0);
        int leftMax = max(solve(root->left) ,0);
        maxi = max(maxi , root->data + rightMax + leftMax);
        return root -> data + max(rightMax ,leftMax);
    }
  public:
    int findMaxSum(Node *root) {
        if(root == NULL)return 0;
        solve(root);
        return maxi;
    }
};
