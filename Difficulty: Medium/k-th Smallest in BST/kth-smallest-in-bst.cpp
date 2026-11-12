/*
Definition for Node
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
	int solve(Node* root, int k, int &i) {
		if (!root)
			return - 1 ;
		int left = solve(root ->left, k, i);
		if (left != -1)
			return left ;
		i++ ;
		if (i == k)
			return root -> data ;
		
		return solve(root -> right, k, i);
		
	}
	int kthSmallest(Node *root, int k) {
		// code here
		int i = 0 ;
		return solve(root, k, i) ;
	}
};
