class Solution {
  public:
  int gcdElement(int a , int b){
              if(a == 0 )
         return b ;
         if(b == 0)
         return  a ;
         while(a != b ) {
             if(a > b )
             a = a - b ;
             else 
             b = b - a ;
         }
      return a ;
  }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
       vector <int> ans ;
        int lcm , gcd ;
gcd = gcdElement(a , b ) ;
     lcm = (a * b) / gcd ;
     ans.push_back(lcm) ;
     ans.push_back(gcd) ;
     return ans ;
    }
};