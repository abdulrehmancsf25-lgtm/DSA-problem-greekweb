/* Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	Node* solve(Node* root, int &k, int node) {
		if (!root)
			return NULL ;
		if (root -> data == node)
			return root ;
		Node* lft = solve(root -> left, k, node) ;
		Node* rgt = solve(root -> right, k, node) ;
		
		if (lft || rgt) {
			k-- ;
			if (k == 0) {
				k = -1 ;
				return root ;
			}
			
		}
		if (lft)
			return lft ;
		if (rgt)
			return rgt ;
		return NULL ;
	}
	int kthAncestor(Node *root, int k, int node) {
		// code here
		Node* ans = solve(root, k, node) ;
		if (k > 0)
			return - 1 ;
		return ans -> data ;
	}
};
