import time
import random
import os
name=input("Enter any sentence: ")
Len=len(name)
timelength=5
while timelength>0:
	for i in range(Len):
		os.system("cls")
		n=random.randint(31,36)
		if ord(name[i])==32:
			i=i+1
			continue
		temp=name[i:Len]
		line=str("\033[1;"+str(n)+";40m "+temp)
		print(line)
		time.sleep(0.4)
	else:
		timelength-=1
print("\033[m")
