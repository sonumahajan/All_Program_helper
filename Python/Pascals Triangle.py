def generate(n):
    a=[]
    for i in range(n):
        b=[]
        val=1
        num=i
        den=1
        for j in range(i):
            b.append(val) 
            val=(val*num)//den
            num-=1
            den+=1
        b.append(1)
        a.append(b)
    return a



n=int(input())
a=generate(n)
for i in a:
    print(i)
