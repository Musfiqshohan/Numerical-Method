from sympy import *
from itertools import cycle


def file_to_matrix(file):
    parameter_symbols = set([])

    file1 = open(file, "r")
    dat = file1.read()

    dat = dat.replace(" ", "")
    dat = dat.replace("=", "-")
    #print(dat)

    for i in range(len(dat)):
        if dat[i] >= 'a' and dat[i] <= 'z':
            if ((i + 1) < len(dat) and ('0' <= dat[i + 1] and dat[i + 1] <= '9')):
                parameter_symbols.add(str(dat[i] + dat[i + 1]))
            else:
                parameter_symbols.add(dat[i])
        elif dat[i] >= 'A' and dat[i] <= 'Z':
            if ((i + 1) < len(dat) and ('0' <= dat[i + 1] and dat[i + 1] <= '9')):
                parameter_symbols.add(str(dat[i] + dat[i + 1]))
            else:
                parameter_symbols.add(dat[i])

    tmp = sorted(parameter_symbols)
    tmp1 = ["A", "B", "C", "D", "E", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
    # tmp.reverse()
    # print(tmp1)
    sym = tmp
    for i in range(len(sym)):
        dat = dat.replace(sym[i], tmp1[i])

    generic_symbols = ""
    # print(dat)
    for i in range(len(sym)):
        if i != 0:
            generic_symbols = generic_symbols + " "
        # print(sym[i]+" "+str(i+1))
        dat = dat.replace(tmp1[i], "x" + str(i + 1))
        generic_symbols = generic_symbols + "x" + str(i + 1)
    # print(generic_symbols)
    # print(dat)
    i = 0
    gen = cycle([0])
    # print(gen)
    for itr in gen:
        if (i + 1) < len(dat) and (dat[i] >= '0' and dat[i] <= '9') and dat[i + 1] == 'x':
            dat = dat[:i + 1] + "*" + dat[i + 1:]
        if (i > len(dat)):
            break
        i = i + 1
    # print(dat)
    var = symbols(generic_symbols)
    dat = dat.splitlines()
    eq = dat
    # print(eq)
    AMat, BMat = linear_eq_to_matrix(eq, var)
    # print(AMat)
    # print(BMat)
    A = AMat.tolist()
    # print(A)
    b = []
    for temp in BMat:
        b.append(temp)
    return A, b, sym


if __name__ == '__main__':
    file_to_matrix("input.txt")