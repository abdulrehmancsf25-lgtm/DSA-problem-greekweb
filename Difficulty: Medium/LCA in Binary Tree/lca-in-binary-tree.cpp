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
	bool ancestors(Node* root, int &node, vector<Node*> &v) {
		if (root == NULL)
			return false;
		v.push_back(root) ;
		
		if (root->data == node) {
			return true ;
		}
		
		if (ancestors(root->left, node, v) || ancestors(root->right, node, v))
			return true ;
		
		// 4. Backtrack if target not found in this branch
		v.pop_back();
		return false;
		
	}
	public:
	Node* lca(Node* root, int n1, int n2) {
		//  code here
		if (!root->left && !root -> right)
			return root ;
		vector<Node*> v1 ;
		vector<Node*> v2 ;
		ancestors(root, n1, v1) ;
		ancestors(root, n2, v2) ;
		int len = min(v1.size(), v2.size()) ;
		Node* ans = NULL ;
		for (int i = len - 1 ; i >= 0 ; i--) {
			if (v1[i] == v2[i]) {
				ans = v1[i] ;
				break ;
			}
			
		}
		return ans ;
	}
};
