/* Structure of binary tree node
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
    pair<bool , int> solve(Node* root){
           if(!root){
                 pair<bool , int> p = make_pair(true , 0) ;
                return p ;
           }
        
        pair<bool , int> left = solve(root -> left) ;
        pair<bool , int> right = solve(root -> right) ;
        
        bool op1 = left.first ;
        bool op2 = right.first ;
        bool op3 = abs(left.second - right.second) <= 1 ;
        
        pair<bool , int> ans ;
        ans.first = op1 && op2 && op3 ;
        ans.second = max(left.second , right.second) + 1 ;
        
        return ans ;
    }
  public:
    bool isBalanced(Node* root) {
        // code here
       return solve(root).first ;
    }
};