from turtle import Turtle, Screen
import random

screen = Screen()
screen.setup(width=500, height=400)
user_bet = screen.textinput(title = "Make your bet", prompt= "Which turtle will win the race? Enter a color: ")
colors = ["red", "orange", "yellow", "green", "blue", "purple"]
all_turtles = []

y_coordinate = -70
for turtle_index in range(6): 
    turtle = Turtle(shape = "turtle") 
    turtle.color(colors[turtle_index])  
    turtle.penup()
    turtle.goto(-230, y_coordinate)
    y_coordinate += 30 
    all_turtles.append(turtle)

is_race_on = False

if user_bet:
    is_race_on = True

while is_race_on:
    
    for t in all_turtles:
        if t.xcor() > 230:
            is_race_on = False
            winning_color = t.pencolor()
            if winning_color == user_bet:
                print(f"Congrats! You have won! The {winning_color} turtle is the winner!")
            else:
                print(f"You have lost. The {winning_color} turtle is the winner. ")
                
        random_distance = random.randint(0, 10)
        t.forward(random_distance)

screen.exitonclick()