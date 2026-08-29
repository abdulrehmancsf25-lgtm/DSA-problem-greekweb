/* Structure of Tree Node
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
	public:
	void levelOrderTraversel(Node* root, vector<int> &ans) {
		
		queue<Node*> q ;
		q.push(root) ;
		q.push(NULL) ;
		Node* temp ;
		while (!q.empty()) {
			temp = q.front() ;
			q.pop() ;
			
			if (temp) {
				ans.push_back(temp ->data) ;
				
				if (temp->right)
					q.push(temp->right) ;
				
				if (temp->left)
					q.push(temp->left) ;
			}
			else {
				if (!q.empty())
					q.push(NULL) ;
			}
		}
	}
	
	vector<int> reverseLevelOrder(Node *root) {
		// code here
		vector<int> ans ;
		if (root == NULL)
			return ans ;
		levelOrderTraversel(root, ans) ;
		
		reverse(ans.begin(), ans.end()) ;
		return ans ;
	}
};
