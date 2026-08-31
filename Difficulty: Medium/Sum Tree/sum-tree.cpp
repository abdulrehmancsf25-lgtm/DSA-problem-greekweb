/* Definition for Node
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
	public:
	pair<bool, int> solve(Node* root) {
		if (!root) {
			return {true, 0} ;
		}
		if (!root->left && !root->right)
			return {true, root -> data} ;
		
		pair<bool, int> left = solve(root -> left) ;
		pair<bool, int> right = solve(root -> right) ;
		
		bool op1 = left.first ;
		bool op2 = right.first ;
		bool op3 = (left.second + right.second) == root -> data ;
		
		pair<bool, int> ans ;
		ans.first = op1 && op2 && op3 ;
		ans.second = root->data + left.second + right.second ;
		
		return ans ;
	}
	bool isSumTree(Node* node) {
		// code here
		return solve(node).first ;
	}
};
