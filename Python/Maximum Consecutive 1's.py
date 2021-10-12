#Taking input as list 
n=list(map(int,input().split()))

count_1=0

a=[]

count=0

for i in range(len(n)):

    if n[i]==1:
        a.append(1)
        count+=1  #variable to count the no.of 1's

    else:
        a=[]

        if count_1<count: #checking if the previous count value is greater or not
            count_1=count
            count=0

print( max(count_1,count))
