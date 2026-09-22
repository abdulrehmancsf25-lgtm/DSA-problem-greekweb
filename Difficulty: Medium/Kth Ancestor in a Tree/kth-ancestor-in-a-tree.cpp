/* Definition for Node
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
	bool kth(Node* root, int target, vector<int>& temp) {
		if (root == NULL)
			return false ;
		temp.push_back(root-> data) ;
		if (root -> data == target)
			return true ;
		// calls
		if (kth(root -> left, target, temp) || kth(root -> right, target, temp))
			return true ;
		
		temp.pop_back() ;
		return false ;
	}
	int kthAncestor(Node *root, int k, int node) {
		// code here
		vector<int> temp ;
		bool check = kth(root, node, temp) ;
		if (!check)
			return - 1 ;
		if (temp.size() <= k)
			return - 1 ;
		int S = temp.size() ;
		int i = temp.size() - 1 ;
		for (; i > S - k-1; i--)
			temp.pop_back() ;
		
		return temp.back() ;
		
	}
};
