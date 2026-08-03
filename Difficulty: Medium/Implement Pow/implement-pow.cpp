class Solution {
    private:
            double powFunc(double num , long long  n ){
    if(n == 0 )
    return 1.0 ;
  double ans ;
   if(n & 1){
     ans = powFunc(num ,  n/2) ;
     ans *= num * ans ;
   }
   else{
           ans =  powFunc(num ,  n/2) ;
           ans *= ans ;
   }
   return ans ;
 }
 
  public:
    double power(double b, int e) {
        // code here
         long long  power = e ;
    if(power < 0 ){
        power *= -1 ;
       return   (1.0 /powFunc(b , power)) ;
         }
    else
       return  powFunc(b , power ) ;  
    }
};