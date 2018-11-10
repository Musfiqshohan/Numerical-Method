import equationParse as eParse
import numpy as np
import re
from numpy import linalg

def ToReducedRowEchelonForm(M,r):
    # if not M: return
    lead = 0
    rowCount = r
    columnCount = len(M[0])
    for r in range(rowCount):
        if lead >= columnCount:
            return
        i = r
        while M[i][lead] == 0:
            i += 1
            if i == rowCount:
                i = r
                lead += 1
                if columnCount == lead:
                    return

        t1= np.copy(M[i])
        t2= np.copy(M[r])

        # M[i], M[r] = M[r], M[i]
        M[i]= np.copy(t2)
        M[r]=np.copy(t1)
        lv = M[r][lead]
        M[r] = [mrx / float(lv) for mrx in M[r]]


        for i in range(rowCount):
            if i != r:
                lv = M[i][lead]
                M[i] = [iv - lv * rv for rv, iv in zip(M[r], M[i])]
        lead += 1




matrix,rhs,r= eParse.parseMatrix()





mtx =[]
rows=[]



for i in range(0,r):
    rows = []
    for j in range(0,r):
        rows.append(0)
        if(i==j):
            rows[j]=1

    # print(rows)
    mtx.append(rows)

matrix= np.concatenate((matrix, mtx), axis=1)
print("Main matrix")
print(matrix)

ToReducedRowEchelonForm(matrix,r)

# for rw in matrix:
#     print ', '.join((str(rw[rv]) for rv in range(3, len(rw))))


c= len(matrix[0])
a= matrix[0:r, r:c]
print("Inverse matrix:")
print(a)
X=[]
X= np.matmul(a,rhs)

file = open("Output2.txt", "w")
for i in range(0, len(X)):
    print("x"+str(i+1),X[i])
    s="x"+str(i+1),X[i]
    file.write("x%s = %f\n" %(str(i+1),X[i]))

file.close()
