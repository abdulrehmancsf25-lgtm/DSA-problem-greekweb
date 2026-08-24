class Solution {
	public:
	int startStation(vector<int> &gas, vector<int> &cost) {
		//  code here
		int front = 0 ;
		int deficit = 0 ;
		int bal = 0 ;
		
		for (int i = 0 ; i < gas.size() ; i++) {
			bal += gas[i] - cost[i] ;
			
			if (bal < 0) {
				deficit += bal ;
				bal = 0 ;
				front = i + 1 ;
			}
		}
		if (bal + deficit >= 0)
			return front ;
		return - 1 ;
	}
};
