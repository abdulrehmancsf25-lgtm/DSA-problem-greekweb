/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans ;
        deque<Node*> q ;
        bool level = true ;
        q.push_front(NULL) ;
        q.push_front(root) ;
        
        while(!(q.size() == 1 && q.front() == NULL) ){
            if(level){
                Node*temp = q.front() ;
                q.pop_front() ;
                if(temp){
                         ans.push_back(temp -> data) ;
                        if(temp->left)
                          q.push_back(temp -> left) ;
                        if(temp->right)
                          q.push_back(temp -> right) ;
                }
                else{
                 level=false ;
                 q.push_front(NULL) ;
            }
            }
            else{
                 Node* temp = q.back() ;
                 q.pop_back() ;
                 if(temp){
                     ans.push_back(temp -> data) ;
                     if(temp -> right)
                      q.push_front(temp -> right) ;
                      if(temp -> left)
                       q.push_front(temp -> left) ;
                 }
                 else{
                    level = true ;
                    q.push_back(NULL) ;
                 }
            }
        }
       
    return ans ;
    }
};