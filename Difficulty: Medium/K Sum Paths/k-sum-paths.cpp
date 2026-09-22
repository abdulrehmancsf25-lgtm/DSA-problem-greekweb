/* Structure of Tree Node
class Node {
  public:
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
    void kPath(Node* root , int target , int sum , int &cnt ,
    unordered_map <int,int> &mapping){
        if(root == NULL)
          return ;
        
         sum += root -> data ;
       
         if(mapping.find(sum-target) != mapping.end())
          cnt += mapping[sum-target] ;
        
        if(sum == target)
          cnt++ ;
        
          
        mapping[sum]++ ;
        
       
        
        kPath(root->left , target , sum ,cnt , mapping) ;
        kPath(root->right , target , sum ,cnt , mapping) ;
        mapping[sum]-- ;
        
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        int cnt = 0 ;
        unordered_map <int,int>mp ;
        kPath(root ,  k , 0 , cnt ,mp ) ;
        return cnt ;
    }
};