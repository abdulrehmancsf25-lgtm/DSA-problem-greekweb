class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        for(int i = 1 ;  i < arr.size()  ; i++){
            for(int j = 0 ; j < arr.size() - i ; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j] , arr[ j+1]);
                }
            }
        }
    }
};