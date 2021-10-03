def is_fizz_buzz(num):
    if num % 3 == 0 and num % 5 == 0:
        print(f"{num} is FizzBuzz")
    elif num % 3 == 0:
        print(f"{num} is Fizz")
    elif num % 5 == 0:
        print(f"{num} is Buzz")
    else:
        print(num)

for i in range(1,30):
    is_fizz_buzz(i)
