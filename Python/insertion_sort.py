def ins_sort(seq):
    isort(seq,len(seq))
def isort(seq,k):
    if k>1:
        
        isort(seq,k-1)
        insert (seq,k-1)
def insert (seq,k):
    pos=k
    while(pos>0 and seq[pos]<seq[pos-1]):
        (seq[pos],seq[pos-1])=(seq[pos-1],seq[pos])
        pos=pos-1

# input  after run is of two types
# 1 -- list_name=  list(range(initial,final,interval))
# 2 -- list_name=[list]
    #   ins_sort(list_name)    
