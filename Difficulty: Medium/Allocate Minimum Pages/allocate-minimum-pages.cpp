class Solution {
  public:
  bool ispossible(vector<int> &arr, int k ,long long  mid  ){
int student = 1;
long long  pagesum = 0 ;
for (int i = 0; i < arr.size(); i++){
 if ( pagesum + arr[i] <= mid  ){
    pagesum += arr[i];
 }
else{
    student ++ ;
    if ( student > k || arr[i] > mid){
         return false;
    }
    pagesum = arr[i];
}
}
return true ;
}
    int findPages(vector<int> &arr, int k) {
        // code here
          long long  start = 0 ;
    long  sum   = 0 ;
for ( int i = 0; i < arr.size() ; i++){
sum  += arr[i];
}
   long long  end = sum ;
   long long  mid = start + (end - start) / 2;
   int ans = -1;
   while ( start <= end ){
   if (ispossible(arr ,k , mid )) {
    ans = mid ;
    end = mid -1;
   }
else{
      start = mid + 1;
}
    mid = start + (end - start) / 2 ;
   }
   if (k > arr.size()){return -1;}
   return ans ;
    }
};