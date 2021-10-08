'''
Your task is to write a simple program which pretends to play tic-tac-toe with the user. 
To make it all easier for you, we've decided to simplify the game. Here are our assumptions:
-->>The computer (i.e., your program) should play the game using 'X's;
-->>The user (e.g., you) should play the game using 'O's;
-->>The first move belongs to the computer - it always puts its first 'X' in the middle of the board;
-->>All the squares are numbered row by row starting with 1 (see the example session below for reference)
-->>The user inputs their move by entering the number of the square they choose - the number must be valid, 
    i.e., it must be an integer, it must be greater than 0 and less than 10, and it cannot point to a field which is already occupied;
-->>The program checks if the game is over - there are four possible verdicts:
    the game should continue, or the game ends with a tie, your win, or the computer's win;
-->>The computer responds with its move and the check is repeated;
-->>Don't implement any form of artificial intelligence - a random field choice made by the computer is good enough for the game.
'''
# def display_board(board):
#     # The function accepts one parameter containing the board's current status
#     # and prints it out to the console.


# def enter_move(board):
#     # The function accepts the board current status, asks the user about their move,
#     # checks the input and updates the board according to the user's decision.


# def make_list_of_free_fields(board):
#     # The function browses the board and builds a list of all the free squares;
#     # the list consists of tuples, while each tuple is a pair of row and column numbers.


# def victory_for(board, sign):
#     # The function analyzes the board status in order to check if
#     # the player using 'O's or 'X's has won the game


# def draw_move(board):
# The function draws the computer's move and updates the board.

from random import randrange


def display_board(board):
    print("+-------" * 3, "+", sep="")
    for row in range(3):
        print("|       " * 3, "|", sep="")
        for col in range(3):
            print("|   " + str(board[row][col]) + "   ", end="")
        print("|")
        print("|       " * 3, "|", sep="")
        print("+-------" * 3, "+", sep="")


def enter_move(board):
    ok = False  # fake assumption - we need it to enter the loop
    while not ok:
        move = input("Enter your move: ")
        # is user's input valid?
        ok = len(move) == 1 and move >= '1' and move <= '9'
        if not ok:
            # no, it isn't - do the input again
            print("Bad move - repeat your input!")
            continue
        move = int(move) - 1 	# cell's number from 0 to 8
        row = move // 3 	# cell's row
        col = move % 3		# cell's column
        sign = board[row][col]  # check the selected square
        ok = sign not in ['O', 'X']
        if not ok:  # it's occupied - to the input again
            print("Field already occupied - repeat your input!")
            continue
    board[row][col] = 'O' 	# set '0' at the selected square


def make_list_of_free_fields(board):
    free = []  # the list is empty initially
    for row in range(3):  # iterate through rows
        for col in range(3):  # iterate through columns
            if board[row][col] not in ['O', 'X']:  # is the cell free?
                # yes, it is - append new tuple to the list
                free.append((row, col))
    return free


def victory_for(board, sgn):
    if sgn == "X":  # are we looking for X?
        who = 'me'  # yes - it's computer's side
    elif sgn == "O":  # ... or for O?
        who = 'you'  # yes - it's our side
    else:
        who = None  # we should not fall here!
    cross1 = cross2 = True  # for diagonals
    for rc in range(3):
        if board[rc][0] == sgn and board[rc][1] == sgn and board[rc][2] == sgn:  # check row rc
            return who
        if board[0][rc] == sgn and board[1][rc] == sgn and board[2][rc] == sgn:  # check column rc
            return who
        if board[rc][rc] != sgn:  # check 1st diagonal
            cross1 = False
        if board[2 - rc][2 - rc] != sgn:  # check 2nd diagonal
            cross2 = False
    if cross1 or cross2:
        return who
    return None


def draw_move(board):
    free = make_list_of_free_fields(board)  # make a list of free fields
    cnt = len(free)
    if cnt > 0:  # if the list is not empty, choose a place for 'X' and set it
        this = randrange(cnt)
        row, col = free[this]
        board[row][col] = 'X'


board = [[3 * j + i + 1 for i in range(3)]
         for j in range(3)]  # make an empty board
board[1][1] = 'X'  # set first 'X' in the middle
free = make_list_of_free_fields(board)
human_turn = True  # which turn is it now?
while len(free):
    display_board(board)
    if human_turn:
        enter_move(board)
        victor = victory_for(board, 'O')
    else:
        draw_move(board)
        victor = victory_for(board, 'X')
    if victor != None:
        break
    human_turn = not human_turn
    free = make_list_of_free_fields(board)

display_board(board)
if victor == 'you':
    print("You won!")
elif victor == 'me':
    print("I won")
else:
    print("Tie!")
