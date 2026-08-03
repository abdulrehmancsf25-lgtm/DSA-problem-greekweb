class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
              if(arr.size() == 1)
              return {-1} ;
             int smallestElement = INT_MAX , secSmallest = INT_MAX ;
            
            for(int i = 0 ; i < arr.size() ; i++){
                if(arr[i] < smallestElement){
                     secSmallest = smallestElement ;
                    smallestElement = arr[i] ; 
                }
            else if(arr[i] != smallestElement && arr[i] < secSmallest)
                secSmallest = arr[i] ;
                
            }
        if(secSmallest == INT_MAX )
         return {-1} ;
    else
        return{smallestElement , secSmallest} ;
    }
};