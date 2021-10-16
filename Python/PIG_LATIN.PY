def PigLatin(line):
    changed=[]
    firIndex=[0]
    suffix='ay'
    b=0
    c=0
    def spaceIndex(lst):
        a=0
        spaceindex=[]
        for i in changed:
            if i.isspace():
                spaceindex.append(a)
            a=a+1
        return spaceindex
    
    for i in line:
        changed.append(i)
    changed.append(" ")

    
    for i in changed:
        if i.isspace():
            firIndex.append(b+1)
        b=b+1

    
    space=spaceIndex(changed)
    for i in space:
        changed.insert(i,changed[c]+suffix)
        changed.pop(c)
        
        c=i+1

    
    return changed


line=input("ENTER A SENTENCE:")
pig_latin = PigLatin(line)
print("original line is :",line)
print("pig latin line is: ",end='')
for i in pig_latin:
    print(i,end='')
