'''font styles
1- alphabet
2- 3-d
3- slant
4- 5lineoblique
5- banner3-D
6-isometric1
7-letters
8-alligator
9-dotmatrix
10-bubble
11-doh

'''
import pyfiglet
print("\033[1;"+"32"+";40m "+" ")
name=input('ENTER NAME:')
print("\033[m")
name=str(name).upper()
while 1:
	choice=int(input("Press 1 to continue \n 0 to exit"))
	if(choice==1):
		try:
			print("\033[1;"+"32"+";40m "+" ")
			style=input('ENTER STYLE:')
			print("\033[m")
			style=str(style)
			word=pyfiglet.figlet_format(name,font=style)
			print("\033[1;"+"34"+";40m "+" ")
			print(word)
			print("\033[m")
		except:
			print("\033[1;"+"31"+";40m"+"WRONG FONT STYLE")
			print("\033[1;"+"32"+";40m "+" ")
			style=input('ENTER STYLE:')
			print("\033[m")
			style=str(style)
			word=pyfiglet.figlet_format(name,font=style)
			print("\033[1;"+"34"+";40m "+" ")
			print(word)
			print("\033[m")
	elif(choice==0):
		break
	else:
		print("\033[1;"+"31"+";40m "+" ")
		print("Wrong choice")
		print("\033[m")
