class Solution {
  public:
   bool binSearch(vector<vector<int>> &mat, int x , int s ,int e,int size ){
       // base case 
       if(s > e)
        return false ;
        // process
        int mid = s + (e-s)/2 ;
        if(mat[mid/size][mid % size] == x)
         return true ;
        else if(mat[mid/size][mid  % size] < x)
          return binSearch(mat,  x , mid +1 , e, size ) ;
        else
        return  binSearch(mat, x , s ,mid -1 , size ) ;
   }
    bool searchMatrix(vector<vector<int>> &mat, int x ) {
        // code here
        int rows = mat.size() ;
        int cols  = mat[0].size() ;
        return binSearch(mat , x , 0 ,rows*cols -1 , cols ) ;
    }
    
};