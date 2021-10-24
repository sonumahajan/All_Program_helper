import turtle as t
import time as ti
import random as rd

t.bgcolor("grey")
gameon=False

snake=t.Turtle()
snake.shape("square")
snake.speed(0)
snake.penup()
snake.color("blue")
snake.hideturtle()

text=False
text=t.Turtle()
text.write("Press Enter to start",align="center",font=("Algerian",28,"bold","underline"))
text.hideturtle()

score=t.Turtle()
score.hideturtle()
score.speed(0)
score.hideturtle()

high_score=t.Turtle()
high_score.hideturtle()
high_score.speed(0)
high_score.hideturtle()

h_score=0

food=t.Turtle()
food_shape=((0,0),(10,8.5),(10,16),(5,25),(10,33.5),(10,42),(0,50),(-10,42),(-10,33.5),(-5,25),(-10,16),(-10,8.5))
t.register_shape("food",food_shape)
food.shape("food")
food.color("brown")
food.penup()
food.speed()
food.hideturtle()

def scoreboard(current_score):
    score.clear()
    score.penup()
    y=t.window_height()/2-40
    x=t.window_width()/2-20
    score.setpos(x,y)
    score.write("Score : "+str(current_score),align="right",font=("Algerian",28,"bold","underline"))
    global h_score
    high_score.clear()
    high_score.penup()
    high_score.setpos(-60,y)
    high_score.write("TOP SCORE : "+str(h_score),align="right",font=("Algerian",28,"bold","underline"))


def food_placed():
    food.hideturtle()
    food.setx(rd.randint(-200,200))
    food.sety(rd.randint(-200,200))
    food.showturtle()

def on_walls():
    leftw=-t.window_width()/2
    rightw=t.window_width()/2
    topw=t.window_height()/2
    bottomw=-t.window_height()/2
    x,y=snake.pos()
    atWall = x<=leftw or x>=rightw or y>=topw or y<=bottomw
    return atWall

def game_over():
    snake.color("grey")
    food.color("grey")
    t.penup()
    t.hideturtle()
    t.write("GAME OVER !\nPress SPACE to play again.",align="center",font=("Algerian",28,"bold","underline"))

def restart_game():
    global gameon
    t.clear()
    gameon=False
    snake.color("blue")
    food.color("brown")
    snake.setx(0)
    snake.sety(0)
    start_game()

def start_game():
    global gameon
    if gameon:
        pass
    else :
        gameon=True
        score=0
        text.clear()
        snake_speed=2
        snake_length=3
        snake.shapesize(1,snake_length,1)
        snake.showturtle()
        scoreboard(score)
        food_placed()
        
        while True:
            snake.forward(snake_speed)
            if snake.distance(food)<35:
                food_placed()
                snake_length+=1
                snake_speed+=1
                snake.shapesize(1,snake_length,1)
                score+=10
                global h_score
                h_score=max(h_score,score)
                scoreboard(score)
            if on_walls():
                game_over()
                break

def move_up():
    if snake.heading()==0 or snake.heading()==180 :
        snake.setheading(90)

def move_down():
    if snake.heading()==0 or snake.heading()==180 :
        snake.setheading(270)

def move_left():
    if snake.heading()==90 or snake.heading()==270 :
        snake.setheading(180)

def move_right():
    if snake.heading()==90 or snake.heading()==270 :
        snake.setheading(0)

t.onkey(start_game,"Return")
t.onkey(restart_game,"space")

t.onkey(move_up,"Up")
t.onkey(move_down,"Down")
t.onkey(move_left,"Left")
t.onkey(move_right,"Right")

t.onkey(move_up,"w")
t.onkey(move_down,"s")
t.onkey(move_left,"a")
t.onkey(move_right,"d")

t.listen()
t.mainloop()

ti.sleep(3)