class Solution:
    def sort012(self, arr):
        # code here
        i = k = 0
        j = len(arr)-1
        while k <= j :
            if arr[k] == 1:
                k += 1
            elif arr[k] == 2:
              arr[k],arr[j] = arr[j],arr[k]
              j -= 1
            else:
                arr[k],arr[i] = arr[i],arr[k]
                k += 1
                i += 1
            
          
                
            