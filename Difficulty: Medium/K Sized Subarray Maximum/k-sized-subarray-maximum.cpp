class Solution {
	public:
	vector<int> maxOfSubarrays(vector<int>& arr, int k) {
		// we have to store elements index in decreasing order in queue
		// we want our window max at front
		// if new element is gretaer than deque.back() we have to pop_back
		// untill new max is its right position
		
		vector<int> ans ;
		deque<int> q ;
		// process first window
		for (int i = 0 ; i < k ; i++) {
			if (q.empty()) // empty case
				q.push_back(i) ;
			else {
				while (!q.empty() && arr[q.back()] <= arr[i])
					q.pop_back() ; // poping min elements from back compare to i
				
				q.push_back(i) ; // pushing i at right place
			}
		}
		ans.push_back(arr[q.front()]) ;
		
		// for next windows
		for (int i = k ; i < arr.size() ; i++) {
			// check for window size
			while (!q.empty() && i - q.front() >= k)
				q.pop_front() ;
			// revise first window logic
			if (q.empty())
				q.push_back(i) ;
			else {
				while (!q.empty() && arr[q.back()] <= arr[i])
					q.pop_back() ;
				
				q.push_back(i) ;
			}
			ans.push_back(arr[q.front()]) ;
		}
		
		return ans ;
	}
};
