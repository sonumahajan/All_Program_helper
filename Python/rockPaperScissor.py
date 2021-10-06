'''
This is a Rock Sicssor Paper Game on Command Line in Python 
This is a single player Game (i.e. one player at time the opponent is computer whose choice is totally random )
'''

import random
score=0
compScore=0
Turns=0
draw=0

while True:
    try:
        print(
"""
Your Option are(type number which is given in front of each option):
Rock[1]
Paper[2]
Scissor[3]
Show score[4]  
Quit[5]""")
        User_choice=int(input("Enter your choice: ")) # Take user input 
        print("")
        comp_choice=random.randint(1,3) # Create random comp choice b/3 1 and 3
        if User_choice<4 and User_choice>0:
            # The Loggic of the Game to Count Point and Detect Winner 
            if comp_choice==1:
                print("Computer:Rock")
                if User_choice==2:
                    print("You: Paper")
                    print("You Won ")
                    score+=1
                elif User_choice==3: 
                    print("You: Scissor")
                    print("You Loose")
                    compScore+=1
                else:
                    print("You: Rock")
                    print("Draw")
                    draw+=1
            elif comp_choice==2:
                print("Computer:Paper")
                if User_choice==3:
                    print("You: Scissor")
                    print("You Won ")
                    score+=1
                elif User_choice==1: 
                    print("You: Rock")
                    print("You Loose")
                    compScore+=1
                else:
                    print("You: Paper")
                    print("Draw")
                    draw+=1
            elif comp_choice==3:
                print("Computer:scissor")
                if User_choice==1:
                    print("You: Rock")
                    print("You Won ")
                    score+=1
                elif User_choice==2:
                    print("You: Paper") 
                    print("You Loose")
                    compScore+=1
                    
                else:
                    print("You: Scissor")
                    print("Draw")
                    draw+=1
            Turns+=1
            

        if User_choice==4:
                print(f"No of Turns: {Turns}")
                print(f"YOUR SCORE: {score}")
                print(f"Computer SCORE: {compScore}")
                print(f"Draw: {draw}")
        elif User_choice==5:
                print("Good Bye, Have a Nice Day.")
                break
            
        elif User_choice>5 or User_choice<=0 : 
            print("Choice is not an option")

    except:
        print("Choice is not an option.")
        continue

