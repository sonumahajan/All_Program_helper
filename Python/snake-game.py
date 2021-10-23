import pygame as pg
import random

pg.init()

white = (255,255,255)
red = (255,0,0)
black = (0,0,0)

screenWidth = 900
screenHeight = 600
gameWindow = pg.display.set_mode((screenWidth,screenHeight))

pg.display.set_caption('Snake Game')
pg.display.update()
clock = pg.time.Clock()
font = pg.font.SysFont(None,55)

def textScreen(text,color,x,y):
    screenText = font.reader(text,True,color)
    gameWindow.blit(sctreenText,[x,y])

def plotSnake(gameWindow,color,snakeList,snakeSize):
    for x,y in snakeList:
        pg.draw.rect(gameWindow, color, [x,y,snakeSize,snakeSize])


def gameLoop():
    exitGame = False
    gameOver = False
    snakeX = 45
    snakeY = 55
    velocityX = 0
    velocityY = 0
    snakeList - []
    snakeLength = 1

    foodX = random.randint(20, screenWidth-20)
    foodY = random.randint(60, screenHeight-20)
    score = 0
    initialVelocity = 4
    snakeSize = 30
    fps = 60

    while not exitGame:
        if gameOver:
            gameWindow.fill(white)
            textScreen('Game Over! Press Enter To Continue',red,100,250)

            for event in pg.event.get():
                if event.type == pg.QUIT:
                    exitGame = True

                if event.type == pg.KEYDOWN:
                    if event.key == pg.K_RETURN:
                        gameLoop()

        else:
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    exitGame = True

                if event.type == pg.KEYDOWN:
                    if evemt.key == pg.K_RIGHT:
                        velocityX = initialVelocity
                        velocityY = 0 

                    if evemt.key == pg.K_LEFT:
                        velocityX = -initialVelocity
                        velocityY = 0 
                    
                    if evemt.key == pg.K_UP:
                        velocityY = -initialVelocity
                        velocityX = 0 

                    if evemt.key == pg.K_RIGHT:
                        velocityY = initialVelocity
                        velocityX = 0 

            snakeX = snakeX + velocityX
            snakeY = snakeY + velocityY

            if abs(snakeX - foodX) < 10 and abs(snakeY - foodY) < 10:
                score += 1
                foodX = random.randint(20, screenWidth-30)
                foodY = random.randint(60, screenHeight-30)
                snakeLength += 5 

            gameWindow.fill(white)
            textScreen("Score : " + str(score*10), red, 5, 5)
            pg.draw.rect(gameWindow, red, [foodX, foodY, snakeSize, snakeSize])
            pg.draw.line(gameWindow, red, (0,40), (900,40), 5)

            head = []
            head.append(snakeX)
            head.append(snakeY)
            snakeList.append(head)

            if len(snakeList) > snakeLength:
                del snakeList[0]

            if head in snakeList[:-1]:
                gameOver = True

            if snakeX < 0 or snakeX > screenWidth-20 or snakeY < 50 or snakeY > screenHeight-20:
                gameOver = True

            plotSnake(gameWindow, black, snakeList, snakeSize)

        pg.dispaly.update()
        clock.tick(fps)

    pg.quit()
    quit()

gameloop()
