/* Binary Tree Node Structure
class Node {
	int data;
	Node *left;
	Node *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void fill(Node* root, vector<int> &temp) {
		if (root == NULL)
			return ;
		fill(root -> left, temp);
		temp.push_back(root -> data) ;
		fill(root -> right, temp) ;
	}
	bool findTarget(Node *root, int target) {
		// code here.
		vector<int> temp ;
		fill(root, temp);
		for (int i = 0, j = temp.size() - 1 ; i <j ;) {
			if (temp[i]+temp[j] > target)
				j-- ;
			else if (temp[i]+temp[j] < target)
				i++ ;
			else
				return true ;
		}
		return false;
	}
};
