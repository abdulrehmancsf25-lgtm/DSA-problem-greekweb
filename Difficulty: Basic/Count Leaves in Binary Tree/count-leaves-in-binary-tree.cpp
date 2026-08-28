/* A binary tree node has data, pointer to left child
and a pointer to right child
struct Node
{
	int data;
	Node* left;
	Node* right;
}; */

// Class Solution
class Solution {
	public:
	void solve(Node* root, int &cnt) {
		if (!root)
			return ;
		
		if (!(root -> left) && !(root -> right))
			cnt++ ;
		
		solve(root->left, cnt) ;
		solve(root -> right, cnt) ;
		
	}
	// Function to count the number of leaf nodes in a binary tree.
	int countLeaves(Node* root) {
		// write code here
		int cnt = 0 ;
		solve(root, cnt) ;
		return cnt ;
	}
};
