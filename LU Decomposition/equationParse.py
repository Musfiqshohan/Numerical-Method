import numpy as np
import re
from numpy import linalg
import heapq


def parseMatrix():
    # name=open("equations.txt","r")
    pattern=r'([+-]?\d*)([A-Z]|[a-z])(\d*)'
    pattern = re.compile(pattern)
    input = open("equations.txt", "r")
    b = []

    Mat=[]
    coefficients = []
    for line in input:
        line = line.strip().replace(' ', '')
        left, right = line.split('=')
        # print(left)
        # print(pattern.findall(left))
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

            # c_dict.append(vno,coef)
            # print("cof")
            # print(c)
            # print("var")
            # print(v)
            # print("var no")
            # print(vno)



        b.append(int(right))
        # coefficients.append(c_dict)
        # coefficients.sort()


        c_dict.sort()
        for i in   c_dict:
            print(i[0],i[1])
            A.append(i[1])

        print("\n")

        # print(A)
        Mat.append(A)



    input.close()
    # print(b)
    # print(coefficients)
    return Mat, b, len(b)