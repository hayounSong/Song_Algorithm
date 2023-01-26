import sys

N=int(sys.stdin.readline())

inputlist=[0]*10001

max=0

for i in range(0,N):
    A=int(sys.stdin.readline())
    inputlist[A]=inputlist[A]+1
    

for i in range(0,10001):
    for c in range(0,inputlist[i]):
        print(i)

