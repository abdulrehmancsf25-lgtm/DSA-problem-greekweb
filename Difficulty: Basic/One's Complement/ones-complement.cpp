class Solution {
  public:
    int onesComplement(int N) {
        // code here
        int x = N ;
        int mask = 0 ;
       if (N == 0)
       return 1 ;
        while(x != 0){
            mask = (mask << 1 ) | 1 ;
            x >>= 1 ;
        }
       int ans= (~N) & mask ;
        return ans ;
    }
};