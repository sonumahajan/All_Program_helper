    # Python Program to ask the user for a range and display all Armstrong numbers in that interval
     
    # take input from the user
    lower = int(input("Enter lower range: "))
    upper = int(input("Enter upper range: "))
     
    for num in range(lower,upper + 1):
       # initialize sum
       sum = 0
     
       # find the sum of the cube of each digit
       temp = num
       while temp > 0:
           digit = temp % 10
           sum += digit ** 3
           temp //= 10
     
       if num == sum:
           print(num)
