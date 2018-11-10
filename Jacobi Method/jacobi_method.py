import equationParse as eParse
import numpy as np
from pprint import pprint


def Jacobi(idx, INPUT):

    # print(idx)
    # print(INPUT)

    res=b[idx]
    for i in xrange(len(INPUT)):
        if(i!=idx):
            res= res- INPUT[i]*A[idx][i];

    res=res/A[idx][idx];

    return res





A,b,d1= eParse.parseMatrix()

print("Dimension")
# print(A)
# print(b)
print(np.size(A,0),np.size(A,1))
if(np.size(A,0)!=np.size(A,1)):
    print("Lu decomposition not possible")
    exit(0)


print("Main Matrix:")
print(A)
print("RHS")
print(b)

INPUT=[]
# INPUT.append(0)
# INPUT.append(0)
# INPUT.append(0)
print("Initial guess\n")
for i in xrange(len(b)):
    x=float(input())
    INPUT.append(x)

iteration=input("Iterations:")

print("Jacobi->")
for iter in xrange(0,iteration):
    Result=[]
    for i in xrange(len(INPUT)):
        x=(Jacobi(i,INPUT))
        Result.append(x)

    print(Result)
    INPUT=Result









