import numpy as np
import re
from numpy import linalg
import heapq
import simpy


def parseMatrix():

    # pattern=r'([+-]?\d+[\.\d+]?)([A-Z]|[a-z])(\d*)' now
    # pattern=r'([+-]?\d*\.\d+)([A-Z]|[a-z])(\d*)'
    pattern = r'([+-]?(\d+(?:\.\d+)?)?)([A-Z]|[a-z])(\d*)'
    pattern = re.compile(pattern)
    input = open("equations.txt", "r")
    b = []

    Mat=[]

    for line in input:
        line = line.strip().replace(' ', '')
        left, right = line.split('=')

        c_dict = []
        A = []
        for c, c_, var,vno in pattern.findall(left):

            # print(c,c_,var,vno)
            if(c == ''  or c == '+'):
                coef = 1.0
            elif c == '-':
                coef = -1.0
            else:
                coef = float(c)

            # print(vno, coef)
            c_dict.append( (var, coef))

        # print("right",right)
        b.append(float(right))

        c_dict.sort()
        for i in   c_dict:
            # print(i[0],i[1])
            A.append(i[1])

        # print("\n")


        Mat.append(A)



    input.close()

    return Mat, b, len(b)


# A,b,d1= parseMatrix()
# print(A)
# print(b)
