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
	void solve(Node* root, unordered_map<int, int> &mapping, int level) {
		if (!root)
			return ;
		
		mapping[level] = root -> data ;
		
		level++ ;
		solve(root -> left, mapping, level) ;
		
		solve(root -> right, mapping, level) ;
		
	}
	vector<int> rightView(Node *root) {
		
		unordered_map<int, int> mapping ;
		int level = 0 ;
		solve(root, mapping, level) ;
		vector<int> ans(mapping.size()) ;
		for (int i = 0 ; i < ans.size() ; i++)
			ans[i] = mapping[i] ;
		return ans ;
	}
};
