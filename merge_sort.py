# Program to perform sorting operation using mergesort algorithm
# To know more about mergesort, please refer https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort

def mergesort(arr):
  
    if len(arr) > 1:
    
        mid = len(arr)//2
        left = arr[:mid]
        right = arr[mid:]

        mergesort(left)
        mergesort(right)
        merge(left, right, arr)

        
def merge(arr1, arr2, arr):
    
    len_1 = len(arr1)
    len_2 = len(arr2)

    i=j=k=0
    
    # Merging elements by comparison
    while i < len_1 and j < len_2:
        if arr1[i] <= arr2[j]:
            arr[k] = arr1[i]
            i+=1
        else:
            arr[k] = arr2[j]
            j+=1
        k +=1
    
    # Adding remaining elements from 1st array, if any
    while i < len_1:
        arr[k] = arr1[i]
        i += 1
        k += 1
    
    # Adding remaining elements from 2nd array, if any
    while j < len_2:
        arr[k] = arr2[j]
        j += 1
        k += 1

arr = [99,0,-2,3,-1,12,15,100,-65]
mergesort(arr)
print(arr)
