class Solution {
  public:
   void solve(stack<int>& s , int cnt){
       if(cnt == 0){
            s.pop() ;
            return ;
       }
       
       int temp = s.top() ;
       s.pop() ;
       solve(s , cnt -1) ;
        s.push(temp) ;
         
   }
    void deleteMid(stack<int>& s) {
        int mid = s.size() /2 ;
        solve(s , mid ) ;
        
    }
};