/* Node Structure
class Node {
	public:
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	void righti(Node *root, vector<int> &ans) {
		if (root == NULL)
			return ;
		if ((root -> left == NULL) && (root -> right == NULL))
			return ;
		if (root -> right)
			righti(root -> right, ans) ;
		else
			righti(root -> left, ans) ;
		ans.push_back(root -> data) ;
		
	}
	void lefti(Node *root, vector<int>&ans) {
		if (root == NULL)
			return ;
		if ((root -> left == NULL) && (root -> right == NULL))
			return ;
		
		ans.push_back(root -> data) ;
		if (root -> left)
			lefti(root->left, ans) ;
		else
			lefti(root-> right, ans) ;
	}
	void leaves(Node *root, vector<int>&ans) {
		if (root == NULL)
			return ;
		if (root -> left == NULL && root -> right == NULL) {
			ans.push_back(root->data) ;
			return ;
		}
		
		leaves(root->left, ans) ;
		leaves(root->right, ans) ;
		
	}
	vector<int> boundaryTraversal(Node *root) {
		// code here
		
		vector<int> ans ;
		if (root == NULL)
			return ans ;
		ans.push_back(root-> data) ;
		if (!root->left && !root->right) {
			return ans;
		}
		lefti(root->left, ans) ;
		leaves(root, ans) ;
		righti(root -> right, ans) ;
		
		return ans ;
	}
};
