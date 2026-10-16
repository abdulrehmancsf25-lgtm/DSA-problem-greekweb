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
	Node* find_predecessor(Node* curr) {
		Node* temp = curr -> left ;

		while (temp -> right && temp -> right != curr) {
			temp = temp -> right ;
		}
		return temp ;
	}
	public:
	vector<int> preOrder(Node* root) {
		// code here
		vector<int> ans ;
		Node* curr = root ;
		while (curr != NULL) {
			if (curr -> left) {
				Node* pred = find_predecessor(curr) ;
				if (pred -> right == NULL) {
					pred -> right = curr ;
					ans.push_back(curr -> data) ;
					curr = curr -> left ;
				}
				else {
					pred -> right = NULL ;
					curr = curr -> right ;

				}
			}
			else {
				ans.push_back(curr -> data) ;
				curr = curr -> right ;
			}

		}
		return ans ;

	}
};
