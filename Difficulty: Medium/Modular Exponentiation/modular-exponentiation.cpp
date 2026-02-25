class Solution {
  public:
    int powMod(int x, int n, int M) {
        // code here
        int result = 1 ;
        while(n > 0){
            if (n & 1)
            result = (1LL *(result ) * (x) %M) % M;
            x = (1LL * (x)%M * (x)%M) %M ;
            
            n = n >> 1 ;
        }
        return result ;
    }
};