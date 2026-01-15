class Solution {
  public:
  bool ispossible(vector<int> &stalls, int k ,int mid ){
      int cowcount = 1;
      int firstposition = stalls[0];
      for (int i = 0 ; i < stalls.size() ; i++){
          if ( stalls[i] - firstposition >= mid ){
              cowcount ++ ;
              if(cowcount == k){return true ;}
              firstposition = stalls[i];
          }
      }
              return false ;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin() ,stalls.end());
        int s = 0;
        int maxim = -1;
        for (int i = 0 ; i < stalls.size() ;i++){
            maxim = max(maxim ,stalls[i]) ;
        }
        int e = maxim ;
        int mid = s + (e-s)/2 ;
        int ans = -1;
        while(s <= e){
        if (ispossible(stalls, k , mid )){
            ans = mid ; 
        s = mid +1 ;}
        else {
            e = mid -1 ;
        }
        mid = s + (e-s)/2 ;
        }
        return ans ;
    }
};