class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
		
		int low = 0, high = mat.size() - 1 ;
		while (low < high) {
			if (mat[low][high] == 1) {
				low++ ;
			}
			else if (mat[low][high] == 0)
				high-- ;
		}
		
		for (int i = 0 ; i < mat.size() ; i++) {
			if (i != high)
				if (mat[i][high] == 0)
					return - 1 ;
			
		}
		for(int j = 0 ; j < mat[0].size() ; j++){
		    if(j != high)
		      if(mat[high][j] == 1)
		        return -1 ;
		}
		return high ;
	}
};
