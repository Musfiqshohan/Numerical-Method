import numpy as np
import re
from numpy import linalg
import equationParse as eParse



matrix,rhs,d1= eParse.parseMatrix()
A = np.copy(matrix)
B = rhs
C = np.copy(matrix)

X = []
for i in range(0, len(B)):

    for j in range(0, len(B)):
        C[j][i] = B[j]
        if i > 0:
            C[j][i - 1] = A[j][i - 1]

    X.append(round(linalg.det(C) / linalg.det(A), 5))



file = open("Output1.txt", "w")
for i in range(0, len(X)):
    print("x"+str(i+1),X[i])
    s="x"+str(i+1),X[i]
    file.write("x%s = %f\n" %(str(i+1),X[i]))

file.close()