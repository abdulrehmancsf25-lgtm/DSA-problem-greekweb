/* Structure of Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	public:
	vector<int> preOrder(Node* root) {
		// code here
		vector<int> ans ;
		stack<Node*> st ;
		Node* curr = root ;
		
		while (curr || !st.empty()) {
			while (curr) {
				ans.push_back(curr -> data) ;
				st.push(curr) ;
				curr = curr -> left ;
			}
			// curr hits null
			curr = st.top() ;
			st.pop() ;
			curr = curr -> right ;
		}
		return ans ;
	}
};
