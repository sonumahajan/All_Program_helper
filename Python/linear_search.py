def linear_search(arr, num):

    for i, element in enumerate(arr):
        if element == num:
            return i
    return -1

arr = [0,-99,87,100,2,6,-13,9]
num = 100
position = linear_search(arr, num)
print(f"{num} found at position {position}")
