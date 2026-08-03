class Solution {
  public:
  int findPower(int n , int expo){
      if(expo == 0)
      return 1 ;
      if(expo == 1)
      return n ;
      int ans = findPower(n , expo/2) ;
      if(expo & 1)
      return n * ans * ans ;
      else
      return ans*ans ;
  }
    int reverseExponentiation(int n) {
        // code here
         int expo = n , ans = 0 ;
         while(expo != 0 ){
            ans =(ans * 10) + (expo % 10) ;
            expo /= 10 ;
         }
        expo = ans ;
    return findPower(n , expo) ;
    }
};