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
	void solve(Node* root, int level, int &maxLevel, int sum,
	int& maxSum) {
		if (root == NULL) {
			if (level > maxLevel) {
				maxLevel = level ;
				maxSum = sum ;
			}
			else if (level == maxLevel)
				maxSum = max(sum, maxSum) ;
			
			return ;
		}
		level++ ;
		sum += root -> data ;
		
		solve(root -> left, level, maxLevel, sum, maxSum) ;
		solve(root -> right, level, maxLevel, sum, maxSum) ;
		
	}
	public:
	int sumOfLongRootToLeafPath(Node *root) {
		// code here
		int maxLevel = 0, maxSum = 0 ;
		solve(root, 0, maxLevel, 0, maxSum) ;
		return maxSum ;
	}
};
