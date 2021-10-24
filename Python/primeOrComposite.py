userEntry = int(input("Enter a number: "))

if userEntry > 1:
    for i in range(2, userEntry):
        if userEntry % i == 0:
            print(userEntry, "is a Composite Number.")
            break
    else:
        print(userEntry, "is a Prime Number.")
elif userEntry == 0 or userEntry == 1:
    print(userEntry, "is neither a Prime Number nor a Composite number.")
else:
    print(userEntry, "is a Prime Number.")