class Solution {
	public:
	int getMaxArea(vector<int> &arr) {
		
		stack<int> st ;
		
		int n = arr.size() ;
		
		// vectors store next smaller elements indices 
		vector<int> lft(n) ; 
		vector<int> rgt(n) ;
		// right smaller indices 
		for (int i = n - 1 ; i >= 0 ; i--) {
			
			while (st.size() && arr[st.top()] >= arr[i]) {
				st.pop() ;
			}
			
			if (st.empty()) {
				rgt[i] = n ;
				st.push(i) ;
				
			}
			else {
				
				rgt[i] = st.top() ;
				st.push(i) ;
			}
		}
		// empty stack
		while (st.size())
			st.pop() ;
		// left smaller indices 
		for (int i = 0 ; i < n ; i++) {
			
			while (st.size() && arr[st.top()] >= arr[i]) {
				st.pop() ;
			}
			
			if (st.empty()) {
				
				lft[i] = -1 ;
				st.push(i) ;
			}
			else {
				
				lft[i] = st.top() ;
				st.push(i) ;
			}
		}
		
		int maxArea = -1 ;
		for (int i = 0 ; i < n ; i++) {
			
			int width = rgt[i] - lft[i] -1 ;
			int area = arr[i] * width ;
			
			if (area> maxArea)
				maxArea = area ;
		}
		return maxArea ;
	}
};
