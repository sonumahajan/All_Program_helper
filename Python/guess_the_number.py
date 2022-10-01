import random
num=random.randint(0,100)
score=0
life=5
print("=================== sonu ========================")
print("Welcome in Guess the Number Game")
print("Hint- Number is positive and between 1 to 100.")
print("You have only "+str(life)+" life.")
print(" ")
def guess_the_number():
    global life
    a=input("Enter your guess: ")
    a=int(a)
    if life == 0:
        print("You Loss! plese try again")
    else:
        if a==num:
            print("\n")
            print("=====  You Win   =====")
        elif a<num:
            print("Your Guess is less then number.")
            life=life-1
            print("Remaning life",str(life))
            print("----------------------------------")
            guess_the_number()
        elif a>num:
            print("Your Guess is greater then number")
            life=life-1
            print("Remaning life",str(life))
            print("----------------------------------")
            guess_the_number()
guess_the_number()
print("================================================")