class Solution {
    void solve(vector<int> &arr, vector<int> output, int target,  vector<vector<int>> &ans,int index ,int &sum){
        if(sum == target){
            ans.push_back(output) ;
            return ;
        }
        if(sum > target){
            return ;
        }
        for(int i = index ; i < arr.size() ;i++){
            sum += arr[i] ;
            output.push_back(arr[i]) ;
            solve(arr,output,target,ans,i,sum) ;
            sum -= arr[i] ;
            output.pop_back() ;
        }
    }
  public:
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        
        vector<vector<int>> ans ;
        vector<int> output ;
        int index = 0 , sum = 0 ;
        solve(arr,output,target,ans,index,sum) ;
        return ans ;
    }
};