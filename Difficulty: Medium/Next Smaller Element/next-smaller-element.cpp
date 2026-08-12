class Solution {
	public:
	vector<int> nextSmallerEle(vector<int>& arr) {
		//  code here
		stack<int> sml ;
		sml.push(-1) ;
		
		for (int i = arr.size() - 1 ; i >= 0 ; i--) {
			int ans = sml.top() ;
			while (ans >= arr[i]) {
				sml.pop() ;
				ans = sml.top() ;
			}
			int x = arr[i] ;
			arr[i] = ans ;
			sml.push(x) ;
		}
		return arr ;
	}
};
