def maxWindowSum(arr,k):
    n= len(arr)
    if k>n:
        return -1
    i,j=0,0
    currsum = 0
    max_sum = 0
    while j<n:
        currsum +=arr[j]
        if j-i+1<k:
            j+=1
        elif j-i+1==k:
            max_sum = max(max_sum,currsum)
            currsum -=arr[i]
            i+=1
            j+=1
            return max_sum  
    
    
       
       
       
       



#other way to solve sliding window 
def window(arr,k):
    n= len(arr)
    if k>n:
        return -1
    
    currsum = sum(arr[:k])
    max_sum = currsum
    
    for i in range(n-k):
        currsum = currsum -arr[i]+arr[i+k]
        max_sum = max(max_sum,currsum)
    return max_sum
        
    
    
    
    
    
    
    
    
# Example usage:
arr = [2,1,5,1,3,2]
k = 3
print(maxWindowSum(arr,k))  # Output: 9

