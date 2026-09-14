/* Structrue of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(!root)
        return -1 ;
        
        int lft = height(root -> left) ;
        int rgt = height(root -> right) ;
          return (max(lft,rgt) + 1);
    }
};