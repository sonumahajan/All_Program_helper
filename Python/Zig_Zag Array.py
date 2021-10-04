import math
import os
import random
import re
import sys

def minOperations(sentence):
    
    l1=list()
    l2=list()
    l1=arr
    l2=arr
    n=len(arr)
    maxs=max(arr)+1
    mins=min(arr)-1

    lh=0
    for i in range(1,n):
        if i%2!=0 and l1[i]<=l1[i-1]:
            lh+=1
            l1[i]=maxs
        elif i%2==0 and l1[i]>=l1[i-1]:
            lh+=1
            l1[i]=mins
    hl=0
    for i in range(1,n):
        if i%2!=0 and l1[i]>=l1[i-1]:
            hl+=1
            l2[i]=maxs
        elif i%2==0 and l1[i]<=l1[i-1]:
            hl+=1
            l2[i]=mins
    return min(lh,hl)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = []

    for _ in range(arr_count):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = minOperations(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
