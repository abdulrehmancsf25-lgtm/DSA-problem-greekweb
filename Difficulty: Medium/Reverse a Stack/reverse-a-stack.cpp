class Solution {
	public:
	void solve(stack<int> &st, int x) {
		// base case
		if (st.empty()) {
			st.push(x) ;
			return ;
		}
		
		int prev = st.top() ;
		st.pop() ;
		solve(st, x) ;
		st.push(prev) ;
		
	}
	
	void reverseStack(stack<int> &st) {
		if (st.empty())
			return ;
		
		int temp = st.top() ;
		st.pop() ;
		reverseStack(st) ;
		solve(st, temp) ;
		
	}
};
