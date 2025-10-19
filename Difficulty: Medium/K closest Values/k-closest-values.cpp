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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    void solve(Node* root, int t){
        if(root == NULL)return;
        solve(root -> left, t);
        pq.push({abs(root -> data - t), root -> data});
        solve(root -> right, t);
    }
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> ans;
        solve(root, target);
        while(!pq.empty() && k --){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};