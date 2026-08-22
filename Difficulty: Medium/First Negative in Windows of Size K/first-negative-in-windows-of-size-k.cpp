class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// code here
		queue<int> q ;
		vector<int> ans ;
		
		for (int i = 0 ; i < k ; i++) { // traverse first window
			if (arr[i] < 0)
				q.push(i) ;
		}
		
		if (q.empty()) // if no neg. element found
			ans.push_back(0) ;
		else
			ans.push_back(arr[q.front()]) ;
		
		for (int i = k ; i < arr.size() ; i++) { // traverse next part
			
			if (!q.empty() && i - q.front() >= k) // if window size is equal to k
				q.pop() ; // remove front
			
			if (arr[i] < 0)
				q.push(i) ;
			
			if (q.empty())
				ans.push_back(0) ;
			else
				ans.push_back(arr[q.front()]) ;
		}
		return ans ;
	}
};
