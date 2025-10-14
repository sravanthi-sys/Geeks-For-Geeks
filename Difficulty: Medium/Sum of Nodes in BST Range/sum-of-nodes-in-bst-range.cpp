/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        int sum = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            while(s --){
                Node* temp = q.front();
                q.pop();
                if(l <= temp -> data && temp -> data <= r)sum += temp -> data;
                if(temp -> left)q.push(temp -> left);
                if(temp -> right)q.push(temp -> right);
            }
        }
        return sum;
    }
};
