/* Structure of a Binary Search Tree node
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
}; */

class Solution {
	Node* findPred(Node* &root, int &key) {
		Node* temp = root ;
		Node* pred = NULL ;
		if (!temp)
			return pred ;
		while (temp != NULL) {
			if (temp -> data < key) {
				pred = temp ;
				temp = temp -> right ;
			}
			else
				temp = temp -> left ;
			
		}
		return pred ;
	}
	Node* findSuc(Node* &root, int &key) {
		Node* temp = root ;
		Node* suc = NULL ;
		if (!temp)
			return suc;
		while (temp != NULL) {
			if (temp -> data > key) {
				suc = temp ;
				temp = temp -> left ;
			}
			else {
				temp = temp -> right ;
			}
		}
		return suc ;
	}
	public:
	vector<Node*> findPreSuc(Node* root, int key) {
		// code here
		vector<Node*> ans(2);
		ans[0] = findPred(root, key) ;
		ans[1] = findSuc(root, key) ;
		return ans ;
	}
};
