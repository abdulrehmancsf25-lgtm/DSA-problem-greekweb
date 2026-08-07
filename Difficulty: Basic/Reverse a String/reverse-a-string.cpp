class Solution {
	public:
	string reverseString(string& s) {
		// code here
		stack <char> temp ;
		for (auto i : s) {
			temp.push(i) ;
		}
		string ans = "" ;
		while (!temp.empty()) {
			ans += temp.top() ;
			temp.pop() ;
		}
		return ans ;
	}
};
