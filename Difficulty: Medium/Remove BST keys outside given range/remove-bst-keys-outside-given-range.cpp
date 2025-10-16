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
    Node* getRight(Node* n) {
        while (n->right) n = n->right;
        return n;
    }
    Node* delNode(Node* root) {
        Node* rightC = root->right;
        Node* leftRight = (root->left) ? getRight(root->left) : NULL;
        if (leftRight) {
            leftRight->right = rightC;
            Node* lftNode = root->left;
            delete root;
            return lftNode;
        }
        else {
            delete root;
            return rightC;
        }
    }
    Node* solve(Node* root, int l, int r) {
        if (!root) return NULL;
        
        while (root && (root->data < l || root->data > r)) {
            root = delNode(root);
        }
        
        if (!root) return NULL;
        
        Node* lft = solve(root->left, l, r);
        Node* rht = solve(root->right, l, r);
        
        root->left = lft;
        root->right = rht;
        return root;
    }
  public:
    Node* removekeys(Node* root, int l, int r) {
        return solve(root, l, r);
    }
};