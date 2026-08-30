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
	pair<bool, int> fast(Node*root) {
		if (!root) {
			pair<bool, int> p = make_pair(true, 0) ;
			return p ;
		}
		
		pair<bool, int> left = fast(root->left) ;
		pair<bool, int> right = fast(root -> right) ;
		
		bool op1 = left.first ;
		bool op2 = right.first ;
		bool op3 = abs(left.second - right.second) <= 1;
		
		pair<bool, int> ans ;
		ans.first = op1 && op2 && op3 ;
		ans.second = 1 + max(left.second, right.second);
		
		return ans ;
	}
	public:
	bool isBalanced(Node* root) {
		return fast(root).first ;
	}
};
