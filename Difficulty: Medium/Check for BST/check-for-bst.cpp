/* Structure of a Binary Search Tree node
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
	bool validateBST(Node* root, int min, int max) {
		if (root == NULL)
			return true ;
		if (root -> data > min && root -> data < max) {
			bool op1 = validateBST(root->left, min, root->data) ;
			bool op2 = validateBST(root -> right, root -> data, max);
			return op1 && op2 ;
		}
		return false; // else cases
	}
	public:
	bool isBST(Node* root) {
		// code here
		return validateBST(root, INT_MIN, INT_MAX);
	}
};
