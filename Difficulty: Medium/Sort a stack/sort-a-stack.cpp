class Solution {
	public:
	void insertInSortedForm(int num, stack<int> &st) {
		if (st.empty()) {
			st.push(num) ;
			return ;
		}
		int temp = st.top() ;
		if (num >= temp) {
			st.push(num) ;
			return ;
		}
		else {
			st.pop() ;
			insertInSortedForm(num, st) ;
			st.push(temp) ;
		}
	}
	void sortStack(stack<int> &st) {
		// code here
		if (st.empty())
			return ;
		
		int temp = st.top() ;
		st.pop() ;
		sortStack(st) ;
		insertInSortedForm(temp, st) ;
	}
};
