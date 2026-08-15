class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        if(mat.size() == 1 && mat[0].size() == 1){
            return 0 ;
        }
        
        
        bool colCheck ;
        vector<int> cols ;
        for(int col = 0 ; col < mat.size() ; col++){
              colCheck = true ;
            for(int row = 0 ; row < mat.size() ; row++){
                if(row != col)
                    if(mat[row][col] != 1){
                        colCheck = false ;
                          break ;
                    }
                
            }
                 if(colCheck == true){
                    cols.push_back(col) ;
                 }
        }
       
       
        bool rowCheck ;
        for(int row = 0 ; row < cols.size() ; row++){
            rowCheck = true ;
            for(int col = 0 ; col < mat.size() ; col++){
                if(cols[row] != col)
                    if(mat[cols[row]][col] != 0){
                        rowCheck = false ;
                        break ;
                    }
            }
              if(rowCheck){
                        return cols[row] ;
                    }
        }
    return -1 ;
    }
};