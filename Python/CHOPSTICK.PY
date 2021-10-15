class CHOPSTICK:
    def GAME_ROUND(STRIKER,OPPONENT,ROUND,P=1):
        print("\033[1;"+"33"+";40m "+"\nA:Attack \nS:Split")
        print("\033[1;"+"32"+";40m "+" ")
        print("Enter move for Player-",P,":",end='')
        CHOICE=input()
        if CHOICE.upper()=="A":
            print("\033[1;"+"33"+";40m"+"\nL L:Left to left of opposition \nL R:Left to right of opposition \nR R:Right to right of opposition \nR L:Right to left of opposition")
            print("\033[1;"+"32"+";40m "+" ")
            if STRIKER[0]==0:
                print("\033[1;"+"36"+";40m "+"\n\nLEFT HAND DEAD!! \nYou can't use L L and L R")
                print("\033[1;"+"32"+";40m "+" ")
            if STRIKER[1]==0:
                print("\033[1;"+"36"+";40m "+"\nRIGHT HAND DEAD!! \nYou can't use R R and R L")
                print("\033[1;"+"32"+";40m "+" ")
            H1,H2=map(str,input("Enter the move combination-").split(' '))
            if H1.upper()=="L" and H2.upper()=="L":
                OPPONENT[0]+=STRIKER[0]
            elif H1.upper()=="L" and H2.upper()=="R":
                OPPONENT[1]+=STRIKER[0]
            elif H1.upper()=="R" and H2.upper()=="R":
                OPPONENT[1]+=STRIKER[1]
            elif H1.upper()=="R" and H2.upper()=="L":
                OPPONENT[0]+=STRIKER[1]
            else:
                print("\033[1;"+"31"+";40m "+"\nInvalid Choice! \nTry again....")
                print("\033[1;"+"32"+";40m "+" ")
                CHOPSTICK.GAME_ROUND(STRIKER,OPPONENT,ROUND,P)
            ROUND+=1
            CHOPSTICK.STATUS(STRIKER,OPPONENT,ROUND)
        elif CHOICE.upper()=="S":
            print("From which hand you want to split-")
            print("L Left Right: Split Left hand into left hand and right hand \nR Left Right: Split Right hand into left hand and right hand")
            SH,LF,RF=map(str,input("Enter split hand and splited numbers-").split(' '))         # SH--> SPLIT HAND, LF--> LEFT FINGER, RF--> RIGHT FINGER
            if SH.upper()=="L":
                if (STRIKER[0]+STRIKER[1]==int(LF)+int(RF)) and int(LF)!=0 and int(RF)!=0:
                    STRIKER[0]=int(LF)
                    STRIKER[1]=int(RF)
                else:
                    print("\033[1;"+"31"+";40m "+"\nWrong Splitting!")
                    print("\033[1;"+"32"+";40m "+" ")
            elif SH.upper()=="R":
                if (STRIKER[0]+STRIKER[1]==int(LF)+int(RF)) and int(LF)!=0 and int(RF)!=0:
                    STRIKER[0]=int(LF)
                    STRIKER[1]=int(RF)
                else:
                    print("\033[1;"+"31"+";40m "+"\nWrong Splitting \nTry again.....")
                    print("\033[1;"+"32"+";40m "+" ")
            else:
                print("\033[1;"+"31"+";40m "+"\nInvalid input!! \nTry again.....")
                print("\033[1;"+"32"+";40m "+" ")
                CHOPSTICK.GAME_ROUND(STRIKER,OPPONENT,ROUND,P)
            
            ROUND+=1
            CHOPSTICK.STATUS(STRIKER,OPPONENT,ROUND)
        else:
            print("\033[1;"+"31"+";40m "+"\nInvalid Choice! \nTry again....")
            print("\033[1;"+"32"+";40m "+" ")
            CHOPSTICK.GAME_ROUND(STRIKER,OPPONENT,ROUND,P)
    LIVE=True
    if LIVE:
        def START(PLAYER1=[1,1],PLAYER2=[1,1],ROUND=1):
            print("\n\ncurrent STATUS:")
            print("PLAYER 1-",PLAYER1[0],"\t",PLAYER1[1])
            print("PLAYER 2-",PLAYER2[0],"\t",PLAYER2[1])
            print("....................................")
            if ROUND%2 !=0:
                STRIKER=PLAYER1
                OPPONENT=PLAYER2
                CHOPSTICK.GAME_ROUND(STRIKER,OPPONENT,ROUND)
            else:
                STRIKER=PLAYER2
                OPPONENT=PLAYER1
                CHOPSTICK.GAME_ROUND(STRIKER,OPPONENT,ROUND,2)
    def STATUS(P1,P2,ROUND):
        if ROUND%2 != 0:
            P1,P2 = P2,P1       
        PLAYER1 =[0 if num>=5 else num for num in P1]
        PLAYER2 =[0 if num>=5 else num for num in P2]
        if PLAYER1[0]==0 and PLAYER1[1]==0:
            print("\n///////PLAYER-1 is terminated, PLAYER-2 is the winner.///////")
            live=False
        elif PLAYER2[0]==0 and PLAYER2[1]==0:
            print("\n///////PLAYER-2 is terminated, PLAYER-1 is the winner.///////")
            live=False
        else:
            CHOPSTICK.START(PLAYER1,PLAYER2,ROUND)
if __name__== "__main__":
    APPLICATION=CHOPSTICK.START()
