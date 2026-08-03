class Solution {
private:
    bool isSafe(vector<vector<int>>& maze ,vector<vector<bool>> &check ,int x ,int y){
        if((x >=0 && x < maze.size()) &&  (y >= 0 && y < maze[0].size()) && (check[x][y] == false) &&
        (maze[x][y] == 1) )
        return true ;
    return false ;
    }
public:
  void solve(vector<vector<int>>& maze ,string &output, vector<string> &ans,vector<vector<bool>> &check,
  int  x ,int y,int &rows,int &cols){
      // base case 
      if(x == rows && y == cols){
        ans.push_back(output) ;
        return ;
      }
       // marking current element as true 
        check[x][y] = true ;
       // right move
       int newx = x , newy = y+1 ;
       if(isSafe(maze , check , newx , newy)){
           output.push_back('R') ;
           solve(maze ,output,ans,check,newx ,newy , rows,cols) ;
           output.pop_back() ;
       }
       // down move
        newx = x+1 ; newy =y ;
        if(isSafe(maze , check , newx , newy)){
           output.push_back('D') ;
           solve(maze ,output,ans,check,newx ,newy , rows,cols) ;
           output.pop_back() ;
       }
       // up move
       newx = x-1 ;  newy = y ;
        if(isSafe(maze , check , newx , newy)){
           output.push_back('U') ;
           solve(maze ,output,ans,check,newx ,newy , rows,cols) ;
           output.pop_back() ;
       }
       // left move
       newx = x ; newy = y-1;
        if(isSafe(maze , check , newx , newy)){
           output.push_back('L') ;
           solve(maze ,output,ans,check,newx ,newy , rows,cols) ;
           output.pop_back() ;
       }
       check[x][y] = false ;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
      
        vector<string> ans ;
        string output = "" ;
        int rows = maze.size()-1 ,cols = maze[0].size()-1 ;
          if(maze[0][0] == 0 ||  maze[rows][cols] == 0)
          return ans ;
        vector<vector<bool>> check(rows+1, vector<bool>(cols+1, false));
        int  x = 0 , y = 0 ;
        solve(maze ,output, ans ,check,x,y,rows,cols) ;
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};