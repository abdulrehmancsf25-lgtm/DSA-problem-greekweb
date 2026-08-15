class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
		stack<int> indices ;
		for (int i = 0 ; i < mat.size() ; i++) {
			indices.push(i) ;
		}
		
		int first, sec ;
		while (indices.size() > 1) {
			first = indices.top() ;
			indices.pop() ;
			if (!indices.empty())
				sec = indices.top() ;
			indices.pop() ;
			
			if (mat[first][sec] == 1)
				indices.push(sec) ;
			else if (mat[sec][first] == 1)
				indices.push(first) ;
			
		}
		if (indices.empty())
			return - 1 ;
		int ptMember = indices.top() ;
		for (int i = 0 ; i < mat.size() ; i++) {
			if (i != ptMember)
				if (mat[i][ptMember] == 0)
					return - 1 ;
		}
		
		for (int i = 0 ; i < mat.size() ; i++) {
			if (i != ptMember)
				if (mat[ptMember][i] == 1)
					return - 1 ;
		}
		return ptMember ;
	}
};
