/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};
*/
class Solution {
	void storeView(Node* root, vector<int> & ans) {
		if (root == NULL)
			return ;
		
		ans.push_back(root -> data) ;
		storeView(root -> left, ans) ;
		storeView(root -> right, ans) ;
	}
	public:
	bool isIdentical(Node* r1, Node* r2) {
		// code here
		vector<int> a ;
		vector<int> b ;
		storeView(r1, a) ;
		storeView(r2, b) ;
		if (a.size() != b.size())
			return false ;
		for (int i = 0 ; i < a.size() ; i++) {
			if (a[i] != b[i])
				return false ;
		}
		return true ;
	}
};
