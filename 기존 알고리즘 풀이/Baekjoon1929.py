

import sys

N=sys.stdin.readline().split(" ")
A=int(N[0])
B=int(N[1])

for b in range(A,B+1):
    icount=0
    for d in range(2,int(b**0.5)+1):
        if b%d==0:
            icount=icount+1
            break
    if(icount==0):
        if(b!=1):
            print(b)