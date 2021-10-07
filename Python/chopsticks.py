print("WELCOME TO THE CHOPSTICKS GAME.....")
print("Always enter values separated by a space.Else error will be thrown.\n\n")
l1 = 1
l2 = 1
r1 = 1
r2 = 1
while(True):
    print("Current status:\nPlayer 1 :", l1, r1, "\nPlayer 2 :", l2, r2, "\n")
    m1 = input("Enter move for player 1(a/s) : ")
    if m1.upper() == 'A':
        a, b = input("Enter attack move : ").split()
        if l2 != 0:
            if a.upper() == 'L' and b.upper() == 'L':
                l2 = l2+l1
            if a.upper() == 'R' and b.upper() == 'L':
                l2 = l2+r1
        if r2 != 0:
            if a.upper() == 'L' and b.upper() == 'R':
                r2 = r2+l1
            if a.upper() == 'R' and b.upper() == 'R':
                r2 = r2+r1
        if (l2 == 0 and (b == 'L' or b == 'l')) or (r2 == 0 and (b == 'R' or b == 'r')):
            print("Can't attack dead hand..")
    if l2 >= 5:
        l2 = 0
    if r2 >= 5:
        r2 = 0
    if l2 == 0 and r2 == 0:
        print("\nPlayer 1 won...")
        break
    if m1.upper() == 'S':
        a, b, c = input("Enter split move : ").split()
        b = int(b)
        c = int(c)
        finger_sum = l1+r1
        split_sum = b+c
        if finger_sum == split_sum:
            l1 = b
            r1 = c
        else:
            print("\nOops!!Can't split.")
    if l1 >= 5:
        l1 = 0
    if r1 >= 5:
        r1 = 0
    if l1 == 0 and r1 == 0:
        print("\nPlayer 2 won...")
        break
    print("\nCurrent status:\nPlayer 1 :", l1,
          r1, "\nPlayer 2 :", l2, r2, "\n")
    m2 = input("Enter move for player 2 : ")
    if m2.upper() == 'A':
        a, b = input("Enter attack move : ").split()
        if l1 != 0:
            if a.upper() == 'L' and b.upper() == 'L':
                l1 = l1+l2
            if a.upper() == 'R' and b.upper() == 'L':
                l1 = l1+r2
        if r1 != 0:
            if a.upper() == 'L' and b.upper() == 'R':
                r1 = r1+l2
            if a.upper() == 'R' and b.upper() == 'R':
                r1 = r1+r2
        if (l1 == 0 and (b == 'L' or b == 'l')) or (r1 == 0 and (b == 'R' or b == 'r')):
            print("Can't attack a dead hand...")
    if l1 >= 5:
        l1 = 0
    if r1 >= 5:
        r1 = 0
    if l1 == 0 and r1 == 0:
        print("\nPlayer 2 won...")
        break
    if m2.upper() == 'S':
        a1, b1, c1 = input("Enter split move : ").split()
        b1 = int(b1)
        c1 = int(c1)
        finger_sum1 = l2+r2
        split_sum1 = b1+c1
        if finger_sum1 == split_sum1:
            l2 = b1
            r2 = c1
        else:
            print("\nOops!!Can't split.")
    if l2 >= 5:
        l2 = 0
    if r2 >= 5:
        r2 = 0
    if l2 == 0 and r2 == 0:
        print("\nPlayer 1 won...")
        break
