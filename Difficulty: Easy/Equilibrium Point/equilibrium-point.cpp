class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        vector<int> left = {0} ;
        int  rightSum =  0 ;
        vector<int> right = {0} ;
        for(int i = arr.size()-2 ; i>= 0 ;i--){
            rightSum += arr[i+1] ;
            right.push_back(rightSum) ;
        }
        reverse(right.begin() , right.end()) ;
        
        int leftSum = 0 ;
        if(leftSum == right[0])
               return  0;
        for(int i = 1 ; i < arr.size() ; i++){
            leftSum += arr[i-1] ;
             if(leftSum == right[i])
               return  i;
        }
    
    return -1 ;
    }
};