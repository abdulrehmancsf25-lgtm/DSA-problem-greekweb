// User function template for C++

class Solution {
  public:
vector<int> findSum(vector<int>&a , vector<int>&b)  {
	int n= a.size();
	int m = b.size();
		int i = n -1 ;
	int j = m -1 ;
	int carry = 0;
	vector<int> ans;
   while(i >= 0 && j>= 0){
       int sum = a[i] + b[j] + carry ;
       carry = sum / 10 ;
       int value = sum % 10 ;
       ans.push_back(value);
       i--;
       j--;
   }
   while(i >= 0){
       int sum = a[i] + carry;
       carry = sum / 10 ;
       int value = sum % 10 ;
       ans.push_back(value);
       i--;
   }
   while(j >= 0){
       int sum = b[j] + carry;
       carry = sum / 10 ;
       int value = sum % 10 ;
       ans.push_back(value);
       j--;
   }
   while(carry != 0){
     int  value = carry;
     carry /= 10 ;
     ans.push_back(value);
       
     
   }
   reverse(ans.begin() , ans.end());
   return ans ;
}
};