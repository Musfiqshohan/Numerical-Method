import numpy as np
import re
from numpy import linalg


def parseMatrix():

    v=open("equations.txt","r")
    matrix= []
    rhs= []

    r=0
    c=0
    for line in v:
        rows = []
        line = line.strip().replace(" ","")
        line=re.split('[A-Z]|=|x[1-9]', line)
        for i in range(len(line)):
            if(line[i]=="" or line[i]=="+"):
                line[i]=1
            if(line[i]=="-"):
                line[i]=-1

            # print(r,c,int(line[i]))

            if(i< len(line)-2):
                rows.append(float(line[i]))
                c=c+1

            if(i== len(line)-1):
                rhs.append(float(line[i]))

        r = r + 1
        c=0
        matrix.append(rows)

    v.close()

    return matrix,rhs,r

