# Write your height in meters
 
height = float(input("Enter your height : "))
print(height)

# Write your weight in kilograms

weight = float(input("Enter your weight : "))
print(weight)
bmi = round(weight / (height * height) , 2)

print("")
print("Your body mass index is : ", bmi)
print("")
if(bmi < 18.5):
    print("You are under weight")

if(bmi > 18.5 and bmi <= 24.9):
    print("You have a normal weight")

if(bmi >= 25 and bmi <= 29.9):
    print("You are over weight")

if(bmi >= 30 and bmi <= 34.9):
    print("You are obese (class I)")

if(bmi >= 35 and bmi <= 39.9):
    print("You are obese (class II)")

if(bmi >= 40):
    print("You are obese (class III)")
