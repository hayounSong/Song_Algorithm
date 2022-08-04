import sys

N=int(sys.stdin.readline())
A=[]
for i in range(0,N):

    num=int(sys.stdin.readline())
    A.append(num)

A=sorted(A)

for n in A:
    print(n)

