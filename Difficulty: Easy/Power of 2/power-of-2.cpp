class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        if ( n <=0)
        return false ;
          int ans = pow(2 , 30 ) ;
        if (( n >=1 && n <= pow(2,30) ) &&  (ans  % n == 0))
              return true ;
    }
};