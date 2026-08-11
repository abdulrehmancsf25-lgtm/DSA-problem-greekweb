class Solution {
	public:
	bool checkRedundancy(string &s) {
		// code here
		if (s.size() == 1)
			return false ;
		
		stack<char> store ;
		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] ==
			'*' || s[i] == '/')
			store.push(s[i]) ;
			
			else if (s[i] == ')') {
				if (store.top() == '(')
					return true ;
				
				while(store.top() != '(')
				   store.pop() ;
				store.pop() ;
			}
		}
		return false ;
	}
};
