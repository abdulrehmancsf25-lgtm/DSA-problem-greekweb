/* Structure of a Binary Search Tree node
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
};
*/

class Solution {
	public:
	Node* findLCA(Node* root, Node* n1, Node* n2) {
		
		while (root) {
			if (root -> data < n1 ->data && root ->data < n2 -> data)
				root = root -> right ;
			
			else if (root -> data > n1 ->data && root ->data > n2 -> data)
				root = root -> left ;
			else
				break ;
		}
		return root ;
	}
};
