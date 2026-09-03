/*
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
}; */

class Solution {
	void solve(Node *root, int sum, int &max_sum, int level, int &max_level) {
		if (root == NULL) {
			if (level > max_level) {
				max_level = level ;
				max_sum = sum ;
			}
			else if (level == max_level) {
				max_sum = max(max_sum, sum) ;
			}
			return ;
		}
		
		sum += root -> data ;
		level++ ;
		
		solve(root->left, sum, max_sum, level, max_level);
		solve(root->right, sum, max_sum, level, max_level);
	}
	public:
	int sumOfLongRootToLeafPath(Node *root) {
		
		int sum = 0, max_sum = 0, level = 0, max_level = INT_MIN ;
		solve(root, sum, max_sum, level, max_level) ;
		return max_sum ;
	}
};
