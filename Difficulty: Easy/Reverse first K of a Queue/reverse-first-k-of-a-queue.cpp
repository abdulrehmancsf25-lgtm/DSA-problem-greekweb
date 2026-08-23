class Solution {
	public:
	void solve(queue<int> &q, int &k, int cnt) {
		if (cnt == k)
			return ;
		
		int fr = q.front() ;
		q.pop() ;
		
		solve(q, k, cnt + 1) ;
		q.push(fr) ;
		
	}
	queue<int> reverseFirstK(queue<int> q, int k) {
		// code here
		int n = q.size() ;
		if (n == 1 || k > n)
			return q ;
		else {
			solve(q, k, 0) ;
			
			for (int i = 0 ; i < n - k ; i++) {
				int fr = q.front() ;
				q.pop() ;
				q.push(fr) ;
			}
		}
		return q ;
	}
};
