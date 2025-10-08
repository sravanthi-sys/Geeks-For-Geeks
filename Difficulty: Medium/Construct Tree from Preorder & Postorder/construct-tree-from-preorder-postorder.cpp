/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    Node* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder, vector<int>& postorder) {
        if (preStart > preEnd) return NULL;
        if (preStart == preEnd) {
            return new Node(preorder[preStart]);
        }
        int leftRoot = preorder[preStart + 1];
        int numOfNodesInLeft = 1;
        while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot) {
            numOfNodesInLeft++;
        }

        Node* root = new Node(preorder[preStart]);
        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, postorder);
        root->right =
            constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                          postStart + numOfNodesInLeft, preorder, postorder);

        return root;
    }
  public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        int numOfNodes = pre.size();
        return constructTree(0, numOfNodes - 1, 0, pre, post);
    }
};