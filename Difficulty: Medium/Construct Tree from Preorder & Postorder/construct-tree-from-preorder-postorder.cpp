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
  public:
    void solve(Node* root, vector<int> &pre, vector<int> &post,
    unordered_map<int,int> &preIdx, unordered_map<int,int> &postIdx,
    int preS, int preE, int postS, int postE) {

        // root node case (return)
        if (preS > preE || postS > postE)
            return;

        // first element of pre vector = left child
        // last element of post vector = right child
        root->left  = new Node(pre[preS]);
        root->right = new Node(post[postE]);

        // map  to find position
        int rPos = preIdx[root->right->data];    // right child in preorder
        int lPos = postIdx[root->left->data];    // left child in postorder

        // left subtree call 
        solve(root->left, pre, post, preIdx, postIdx,
              preS + 1, rPos - 1,
              postS,    lPos - 1);

        // right subtree call
        solve(root->right, pre, post, preIdx, postIdx,
              rPos + 1, preE,
              lPos + 1, postE - 1);
    }

    Node* constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        Node* root = new Node(pre[0]);
        if (n == 1)
            return root;

        unordered_map<int,int> preIdx, postIdx;
        preIdx.reserve(n);
        postIdx.reserve(n);
        for (int i = 0; i < n; i++) {
            preIdx[pre[i]]  = i;
            postIdx[post[i]] = i;
        }

        solve(root, pre, post, preIdx, postIdx, 1, n - 1, 0, n - 2);
        return root;
    }
};