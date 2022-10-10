#Question from hackerrank = https://www.hackerrank.com/challenges/compress-the-string/problem
from itertools import groupby
s=input()
for c,i in groupby(s):
    x=(len(list(i)),int(c))
    print(x, end=" ")
