import re
import numpy as np
import pandas as pd


def make_matrix(coefficients, b):
    b = np.array(b, dtype='float64').reshape(len(b),1)
    A = pd.DataFrame(coefficients)
    A.fillna(0, inplace=True)
    x = list(A.columns.values)
    A = A.values
    # print(b)
    # print(A)
    # print(np.concatenate((A,b),axis=1))
    # print(x)
    return x, A, b


def parse_eqn(name, pattern=r'([+-]?\d*)([A-Z]|[a-z]\d*)'):
    pattern = re.compile(pattern)
    input = open(name, "r")
    b = []
    coefficients = []
    for line in input:
        line = line.strip().replace(' ', '')
        left, right = line.split('=')
        # print(left)
        # print(pattern.findall(left))
        c_dict = {}
        for c, v in pattern.findall(left):
            if(c == '' or c == '+'):
                coef = 1.0
            elif c == '-':
                coef = -1.0
            else:
                coef = float(c)

            c_dict[v] = coef
        b.append(right)
        coefficients.append(c_dict)
    input.close()
    # print(b)
    # print(coefficients)
    return coefficients, b


def cramer(A, b, print_im = False):
    b = np.ravel(b)
    # checking for errors
    if(A.shape[1] != b.shape[0] and A.shape[0] != A.shape[1]):
        print('Wrong')

    soln = np.zeros((1, len(b)))
    det_A = np.linalg.det(A)
    if(print_im):
        print('Determinant: ' + str(det_A))

    for i in range(len(b)):
        temp = np.copy(A)
        temp[:, i] = b
        det_temp = np.linalg.det(temp)
        if(print_im):
            print('Dx' + str(i+1) + '=')
            print(temp)
            print('Determinant of Dx: '+ str(det_A) + str(det_temp))
        soln[0][i] = det_temp/det_A

    return soln.T

def invert(A, partial_pivot = False):

    if(A.shape[0] != A.shape[1]):
        raise ValueError("Not square matrix")
    rows = A.shape[0]
    A = np.concatenate((A, np.identity(rows,dtype='float64')), axis=1)
    # print(A)
    for k in range(rows-1):
        if partial_pivot:
            # Pivot
            maxindex = abs(A[k:, k]).argmax() + k
            if A[maxindex, k] == 0:
                raise ValueError("Matrix is singular.")
            # Swap
            if maxindex != k:
                A[[k, maxindex]] = A[[maxindex, k]]
                b[[k, maxindex]] = b[[maxindex, k]]
        else:
            if A[k, k] == 0:
                raise ValueError("Pivot element is zero.")

        # Elimination
        for row in range(k+1, rows):
            multiplier = A[row, k]/A[k, k]
            A[row, k:] = A[row, k:] - multiplier*A[k, k:]

    for k in reversed(range(rows)):
        A[k, :] = A[k, :]/A[k, k]
        for row in reversed(range(0, k)):
            multiplier = A[row, k]/A[k, k]
            A[row, k:] = A[row, k:] - multiplier*A[k, k:]

    return A[:, rows:]


if __name__ == '__main__':
    p, q = parse_eqn("equations.txt")
    x, A, b = make_matrix(p, q)
    print(np.linalg.inv(A)-invert(A))
    #print(invert(A))
    print(cramer(A,b))
    soln = np.dot(invert(A),b)
    # soln = np.linalg.solve(A, b)
    for i in range(len(b)):
        print(str(x[i]) + " = " + str(soln[i, 0]))
