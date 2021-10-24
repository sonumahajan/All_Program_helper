i = 0
n = int(input("Number: "))
while n != 1:
	if n % 2 == 0:
		n = n/2
	else:
		n = (n*3) + 1
	i+=1
	print("Step "+str(i)+"\t\t"+"n = "+str(n))
if i == 1:
	print("1 step to 1")
else:
	print(str(i)+" steps to 1")