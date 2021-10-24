def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while(p*p<=n):
        if prime[p] == True:
            for i in range(p*p,n+1,p):
                prime[i] = False
        p += 1
    return prime
x = SieveOfEratosthenes(50)
for i in range(2,len(x)):
    if x[i]:
        print(i,end=' ')
