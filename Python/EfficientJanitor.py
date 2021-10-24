#!/bin/python3

import math
import os
import random
import re
import sys


def efficientJanitor(weight):
    count = 0
    i, j = 0, len(weight) - 1
    weight.sort()
    while i <= j:
        count += 1
        if weight[i] + weight[j] <= 3:
            i += 1
        j -= 1
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    weight_count = int(input().strip())

    weight = []

    for _ in range(weight_count):
        weight_item = float(input().strip())
        weight.append(weight_item)

    result = efficientJanitor(weight)

    fptr.write(str(result) + '\n')

    fptr.close()
