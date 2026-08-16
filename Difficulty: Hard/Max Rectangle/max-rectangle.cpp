class Solution {
  private:
   int  largestAreaInhistogram(vector<int> &arr){
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

		if (area > maxArea)
			maxArea = area ;
	}
	return maxArea ;
   }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int maxArea = -1 ;
        // initialize a vector with zeros
        vector<int> ans(mat[0].size() , 0) ;
        
        for(int r = 0 ; r < mat.size() ; r++){
            for(int c = 0 ; c < mat[0].size() ; c++){
                if(mat[r][c] == 0)
                  ans[c] = 0 ;
                else
                ans[c] += mat[r][c] ;
            }
            maxArea = max(largestAreaInhistogram(ans) ,maxArea) ;
        }
    return maxArea ;
    }
};