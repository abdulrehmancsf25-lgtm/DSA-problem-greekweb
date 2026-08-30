/*Structure of binary tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	int height(Node* root) {
		if (root == NULL)
			return 0 ;
		
		int left = height(root -> left) ;
		int right = height(root -> right) ;
		
		return max(left, right) + 1;
	}
	int diameter(Node* root) {
		// code here
		if (root == NULL)
			return 0 ;
		
		int left = diameter(root -> left) ;
		int right = diameter(root -> right) ;
		int total_dist = height(root->left) + height(root -> right) ;
		
		return max(left, max(right, total_dist)) ;
	}
};
