import math
def trailingZeroes(n):
     count=0

     #Finding factorial using math package
     n=math.factorial(n)

     #Checking if the last number is zero or not
     while n%10==0:
          n=n//10
          count+=1
     return count


n=int(input())
print(trailingZeroes(n))
