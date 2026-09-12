/* Structure of Binary Tree Node
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
	vector<int> inOrder(Node* root) {
		// code here
		vector<int> ans ;
		stack<Node*> st ;
		
		Node* curr = root ;
		
		while (curr || !st.empty()) {
			// left process
			while (curr) {
				st.push(curr) ;
				curr = curr -> left ;
			}
			
			curr = st.top() ;
			if (curr)
				ans.push_back(curr -> data) ;
			st.pop() ;
			
			curr = curr -> right ;
		}
		return ans ;
	}
};
