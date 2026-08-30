/* Node Structure
class Node {
	public:
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	int getSize(Node* root) {
		// code here
		if (root == NULL)
			return 0 ;
		
		int left = getSize(root -> left) ;
		int right = getSize(root -> right) ;
		return left + right + 1;
	}
};
