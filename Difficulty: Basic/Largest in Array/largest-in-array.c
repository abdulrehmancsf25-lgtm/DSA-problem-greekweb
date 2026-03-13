// User function template for C
#include <limits.h>
int largest(int arr[], int n) {
    // Code Here
    int maxi = INT_MIN ;
    for(int i= 0 , j = n -1 ; i <= j ; i++ , j--){
         if((arr[i] > arr[j]) && (arr[i] > maxi)  )
            maxi = arr[i] ;
    else if ( (arr[j] >= arr[i] ) && (arr[j] > maxi))
    maxi = arr[j] ;
    
    }
    return maxi ;
}