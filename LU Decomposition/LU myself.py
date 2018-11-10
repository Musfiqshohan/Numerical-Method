import equationParse as eParse
import numpy as np
from pprint import pprint




def LU(A):
    n= len(A);
    L = [[0.0] * n for i in xrange(n)]
    U = [[0.0] * n for i in xrange(n)]

    for i in xrange(n):
        for k in xrange(i,n):
            s=0

            for j in xrange(0,i):
                s+= L[i][j]*U[j][k];

            U[i][k]=A[i][k]-s

        for k in xrange(i,n):
            if(i==k):
                L[i][k]=1
            else:
                s=0
                for j in xrange(0,i):
                    s+=L[k][j]*U[j][i];

                L[k][i]=(A[k][i]-s)/U[i][i];

    return (L,U)


def Forward_substituion(L,b):

    n= len(L)
    for i in xrange(n):
        s=0
        for j in xrange(i):
            s+=L[i][j]*b[j]

        b[i]-=s;

    return b


def Back_substituion(U,y):

    n= len(U)
    for i in xrange(n-1,-1,-1):
        s=0
        for j in xrange(i+1,n):
            s+= U[i][j]*y[j]

        y[i]-=s;
        y[i]/=U[i][i];

    return y


A,b,d1= eParse.parseMatrix()

print(A)
print(b)
print(d1)

print("demo")
print(d1)

print("Dimension")
print(np.size(A,0),np.size(A,1))
if(np.size(A,0)!=np.size(A,1)):
    print("Lu decomposition not possible")
    exit(0)


print("Main Matrix:")
print(A)


if(np.linalg.det(A)==0):
    print("Solution Not Possible")



L,U=LU(A)

print("Lower Triangular matrix")
print(L)
print("Upper Triangular matrix")
print(U)


print("Initial LHS")
print(b)
y=Forward_substituion(L,b)

print("y:")
print(y);

x=Back_substituion(U,y)
print("x:")
print(x)













