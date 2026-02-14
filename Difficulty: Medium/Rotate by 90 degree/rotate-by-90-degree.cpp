class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
          int rows = mat.size(); 
        int cols = mat[0].size();
        // firtst taking transpose
        for(int i = 0 ; i < rows ; i ++ ){
            for(int j = 0 ; j < cols ; j++){
                if(j < i){
                    swap(mat[i][j] , mat[j][i]) ;
                }
            }
        }
        // now swapping columns
     for(int col = 0 ; col< cols ; col++){
            int start = 0 ;
            int end = rows -1 ;
            while(start <= end){
                swap(mat[start++][col] , mat[end--][col]) ;
                    }
        }
    }
};
