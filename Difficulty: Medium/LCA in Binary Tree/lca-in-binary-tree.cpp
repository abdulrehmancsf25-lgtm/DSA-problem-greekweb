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
}; */

class Solution {
	public:
	Node* lca(Node* root, int n1, int n2) {
		//  code here
		if (!root)
			return NULL ;
		if (root -> data == n1 || root -> data == n2)
			return root ;
		
		Node* lft = lca(root -> left, n1, n2) ;
		Node* rgt = lca(root -> right, n1, n2) ;
		
		// possible results
		if (lft && !rgt)
			return lft ;
		if (!lft && rgt)
			return rgt ;
		if (!lft && !rgt)
			return NULL ;
		
		return root ; // LCA if(left & right are both not NULL)
		
	}
};
