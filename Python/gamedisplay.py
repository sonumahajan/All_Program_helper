import pygame
# stting ga
# creating game
# window , title , filling window and game quit loop .
pygame.init()

black = (0,0,0)
white = (255,255,255)
red = (255,0,0)

gameWindow = pygame.display.set_mode((600,400))
pygame.display.set_caption("game title")
gameWindow.fill(red)
pygame.display.update()
go_game = True
def snake(gameWindow, color,snk_list,snk_size):
    for x,y in snk_list:
        pygame.draw.rect(gameWindow, color, [x, y, snk_size, snk_size])
snk_lis=[20,20]
snk_siz=20
while go_game:
    for event in pygame.event.get():
        snake(gameWindow,black,[snk_lis,snk_siz])
        pygame.display.update()
        if event.type == pygame.QUIT:
            go_game = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                print("right key")
pygame.quit()
quit()