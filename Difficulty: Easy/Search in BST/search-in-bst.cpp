/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root)
        return false ;
        if(root -> data == key)
            return true ;
    if(root -> data < key)
            return search(root->right , key) ;
    else
            return search(root -> left , key) ;
    }
};