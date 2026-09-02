/*
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
	vector<int> topView(Node *root) {
		// code here
		
		queue<pair<Node*, int>> q ; // Node and its hor. Distance
		map<int, int> HDtoVal ; // hor.Dist -> node -> value
		vector<int> ans ;
		
		q.push({root, 0}) ; // root node 
		
		while (!q.empty()) {
		    
			pair<Node*, int> temp = q.front() ;
			q.pop() ;
			
			Node* frontNode = temp.first ;
			int horDist = temp.second ;
			// check if a hor.mapping don't exist first 
			if (HDtoVal.find(horDist) == HDtoVal.end())
				HDtoVal[horDist] = frontNode -> data ;
			
			if (frontNode -> left) // distance reduce on left
				q.push({frontNode -> left, horDist - 1}) ;
			
			if (frontNode -> right)  // distance increase on left
				q.push({frontNode -> right, horDist + 1}) ;
			
		}
		for (auto i : HDtoVal) // extract values from map
			ans.push_back(i.second) ;
		return ans ;
	}
};
