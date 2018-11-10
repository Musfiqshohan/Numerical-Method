import numpy as np
import re
from numpy import linalg
import heapq


def parseMatrix():

    pattern=r'([+-]?\d*)([A-Z]|[a-z])(\d*)'
    pattern = re.compile(pattern)
    input = open("equations.txt", "r")
    b = []

    Mat=[]

    for line in input:
        line = line.strip().replace(' ', '')
        left, right = line.split('=')

        c_dict = []
        A = []
        for c, v, vno in pattern.findall(left):
            if(c == ''  or c == '+'):
                coef = 1.0
            elif c == '-':
                coef = -1.0
            else:
                coef = float(c)

            c_dict.append( (vno, coef))


        b.append(int(right))

        c_dict.sort()
        for i in   c_dict:
            print(i[0],i[1])
            A.append(i[1])

        print("\n")


        Mat.append(A)



    input.close()

    return Mat, b, len(b)