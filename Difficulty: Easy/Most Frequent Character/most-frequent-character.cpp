class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        array<int,26> arr = {0} ;
        for(int i =0 ; i < s.size() ;i++ ){
            char ch = s[i];
            int number = 0;
            number = ch - 'a';
            arr[number]++ ;
        }
        int maxim = -1;
        int ans = 0;
        for(int i = 0 ; i<arr.size() ;i++ ){
            if(arr[i] > maxim){
                maxim = arr[i] ;
                ans = i ;
            }
        }
              char temp = ans + 'a';
              return temp;
        
    }
};