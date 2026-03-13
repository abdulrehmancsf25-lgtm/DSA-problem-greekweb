int getSecondLargest(int *arr, int n) {
    // code here
    int largest = arr[0] , secLargest = -1 ;
    for (int i = 1 ; i < n ; i++){
        if(arr[i] > largest) {
           secLargest = largest ;
        largest = arr[i];
        }
        if((arr[i] < largest) && (arr[i] > secLargest))
        secLargest = arr[i] ;
    }
    return secLargest ;
}
