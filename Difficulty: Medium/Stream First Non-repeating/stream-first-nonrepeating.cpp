class Solution {
	public:
	string firstNonRepeating(string &s) {
		
		int arr[26] = {0} ;
		queue<char> q ;
		arr[s[0] - 'a']++ ;
		q.push(s[0]) ;
		int i = 1 ;
		while (i < s.size()) {
			int index = s[i] - 'a' ;
			
			arr[index]++ ;
			
			if (!q.empty()) {
				while (arr[q.front() - 'a'] > 1 && !q.empty())
					q.pop() ;
			}
			
			char ch = s[i] ;
			
			if (q.empty() && arr[index] > 1)
				s[i] = '#' ;
			
			else if (!q.empty())
				s[i] = q.front() ;
			
			q.push(ch) ;
			i++ ;
		}
		
		return s ;
	}
};
