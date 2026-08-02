class Solution:
    def getAlternates(self, arr):
        # Code Here
        return [ arr[x]  for x in range(len(arr)) if not x&1 ]
        