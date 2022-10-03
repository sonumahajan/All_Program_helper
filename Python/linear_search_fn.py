# Program to do linear search by using a function

def lsearch(ar,n,item):
    for i in range(0,n):
        if ar[i]==item:
            return i
            break
    return -1
n=int(input('Enter size of list:'))
print('Enter numbers in sorted order:\n')
ar=[0]*n
for i in range(n):
    ar[i]=int(input('Element '+str(i)+':'))
item=int(input('Enter number to search:'))
index=lsearch(ar,n,item)
if index!=-1:
    print('\nElement found at index :',index,',position: ',(index+1))
else:
    print('\Sorry, the given number is not found')

