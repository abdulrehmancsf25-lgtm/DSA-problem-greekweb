class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        if(arr.size() ==1 )
        return arr[0] ;
        long long  x = 1e9 + 7 ;
       vector<int> positives , negatives ;
       int zeros = 0 ;
     for(int i= 0 ; i< arr.size() ; i++){
        if(arr[i] == 0)
           zeros++;
        else if(arr[i] > 0)
           positives.push_back(arr[i]) ;
        else
           negatives.push_back(arr[i]) ;
    }
    // 1st case
     if(zeros == arr.size())
     return 0 ;
    // calculate prod 
    long long  prod = 1 ;
    for(int i = 0 ; i < positives.size() ;i++)
    prod =( prod%x  * positives[i] % x) % x ;
    // negative case
  // find the negative closest to 0 (maximum among negatives)
 int skipIdx = -1 ;
if(negatives.size() & 1){
skipIdx = 0;
for(int i = 1; i < negatives.size(); i++)
    if(negatives[i] > negatives[skipIdx])
        skipIdx = i;
}
// multiply all negatives except skipIdx
for(int i = 0; i < negatives.size(); i++)
    if(i != skipIdx)
        prod = (prod % x * abs((negatives[i]) % x)) % x;
   
    // next 
    if(negatives.size() == 1 && positives.size() == 0)
    return 0;
    return prod ;
    }
};