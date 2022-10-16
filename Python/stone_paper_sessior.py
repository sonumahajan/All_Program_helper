import random

game=1
total=10
ty=0
win=0
loss=0
print("======================================================")
print(" ")
print("=  Welcome to Sonu,s [ Rock Paper Scissor] Game.  =\n")
print(f"Toatal match is {total}")
print(" Ready to play with computer.\n")
while game<=total:
    # R for rock , p for papper and X for sessior.
    comp =["Rock","Paper","Scissor"]
    comp_ans= random.choice(comp)
    print("Enter [ R for Rock ][ P for Papper ][ X for Scissor]")
    ans = input("==> ")
    ans = ans.upper()
    if(ans=='R'):
        print("Your choice is: Rock")
        if (ans=='R' and comp_ans=='Scissor'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  YOU WIN  ======")
            win+=1
        elif(ans=='S' and comp_ans=='Stone'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  TY  ======")
            ty+=1
        elif(ans=='S' and comp_ans=='Paper'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  You LOSS  ======")
            loss+=1

    elif(ans=='P'):
        print("Your choice is: Paper")
        if (ans=='P' and comp_ans=='Scissor'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  YOU LOSS  ======")
            loss+=1
        elif(ans=='P' and comp_ans=='Stone'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  YOU WIN  ======")
            win+=1
        elif(ans=='P' and comp_ans=='Paper'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  TY  ======")
            ty+=1

    elif(ans=='X'):
        print("Your choice is: Scissor")
        if (ans=='X' and comp_ans=='Scissor'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  TY  ======")
            ty+=1
        elif(ans=='X' and comp_ans=='Stone'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  YOU LOSS  ======")
            loss+=1
        elif(ans=='X' and comp_ans=='Paper'):
            print(f"Computer's choice is: {comp_ans}\n")
            print("======  YOU WIN  ======")
            win+=1
    else:
        print("Invalid Imput!")
    print(f"Game counter {game}")
    print("-------------------------------------------")
    game+=1

print(f""" 
        Total match:   {total}
            You Win:   {win}
           You loss:   {loss}
           Ty match:   {ty}""")
