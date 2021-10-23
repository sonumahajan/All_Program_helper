#Program to check whether the given number is Armstrong or not
from math import *
n1 = int(input("Enter the number : "))
result = 0
n = 0
temp = n1r;
while (temp != 0):
    temp =int(temp / 10)
    n = n + 1

#Checking if the number is armstrong
temp = n1
while (temp != 0):
    remainder = temp % 10
    result = result + pow(remainder, n)
    temp = int(temp/10)
if(result == n1):
    print("Armstrong number")
else:
    print("Not an Armstrong number")
