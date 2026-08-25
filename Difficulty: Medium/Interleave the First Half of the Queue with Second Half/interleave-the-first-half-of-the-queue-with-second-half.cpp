class Solution {
	public:
	void solve(queue<int> &q1, queue<int> &q2) {
		if (q2.empty())
			return ;
		
		int first = q1.front() ;
		int sec = q2.front() ;
		q1.pop() ;
		q2.pop() ;
		
		solve(q1, q2) ;
		q2.push(sec) ;
		q2.push(first) ;
	}
	void reverse_queue(queue<int> &q) {
		if (q.empty())
			return ;
		
		int temp = q.front() ;
		q.pop() ;
		reverse_queue(q) ;
		q.push(temp) ;
	}
	void rearrangeQueue(queue<int> &q) {
		// code here
		queue<int> temp ;
		int n = q.size() / 2 ;
		
		for (int i = 0 ; i < n ; i++) {
			temp.push(q.front()) ;
			q.pop() ;
		}
		
		solve(temp, q) ;
		reverse_queue(q) ;
	}
};
