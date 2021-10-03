import random
def start_game():
    mat = []
    for i in range(4):
        mat.append([0]*4)
    return mat


def compress(mat):
    new_mat = []
    for i in range(4):
        new_mat.append([0]*4)
    for i in range(4):
        pos = 0
        for j in range(4):
            if mat[i][j]!=0:
                new_mat[i][pos] = mat[i][j]
                pos = pos + 1
    return new_mat

def merge(mat):
    for i in range(4):
        for j in range(3):
            if mat[i][j]==mat[i][j+1]:
                mat[i][j] = (mat[i][j])*2
                mat[i][j+1] = 0
    return mat
                
def reverse(mat):
    new_mat = []
    for i in range(4):
        new_mat.append(mat[i][::-1])
    return new_mat

def transpose(mat):
    new_mat = []
    for i in range(4):
        new_mat.append([])
        for j in range(4):
            new_mat[i].append(mat[j][i])
    return new_mat

def move_left(grid):
    new_grid = compress(grid)
    new_grid = merge(new_grid)
    new_grid = compress(new_grid)
    return new_grid

def move_right(grid):
    reverse_grid = reverse(grid)
    new_grid = compress(reverse_grid)
    new_grid = merge(new_grid)
    new_grid = compress(new_grid)
    final_grid = reverse(new_grid)
    return final_grid

def move_up(grid):
    transposed_grid = transpose(grid)
    new_grid = compress(transposed_grid)
    new_grid = merge(new_grid)
    new_grid = compress(new_grid)
    final_grid = transpose(new_grid)
    return final_grid

def move_down(grid):
    transposed_grid = transpose(grid)
    reverse_grid = reverse(transposed_grid)
    new_grid = compress(reverse_grid)
    new_grid = merge(new_grid)
    new_grid = compress(new_grid)
    new_reverse = reverse(new_grid)
    final_grid = transpose(new_reverse)
    return final_grid

mat = start_game()
mat[1][3] = 2
mat[2][2] = 2
mat[3][0] = 4
mat[3][1] = 8
mat[2][1] = 4
inputs = [int(ele) for ele in input().split()]
for ele in inputs:
    if ele == 1:
        mat = move_up(mat)
    elif ele == 2:
        mat = move_down(mat)
    elif ele == 3:
        mat = move_left(mat)
    else:
        mat = move_right(mat)
    print(mat)
    
