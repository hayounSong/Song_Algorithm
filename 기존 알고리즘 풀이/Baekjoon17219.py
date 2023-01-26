import sys

NM=sys.stdin.readline().split(" ")
N=int(NM[0])
M=int(NM[1])

origin={}

new=[]

for i in range(0,N):
    A=sys.stdin.readline().strip().split(" ")
    origin[A[0]]=A[1]

for i in range(0,M):
    A=sys.stdin.readline().strip()
    new.append(A)


for i in range(0,M):
    print(origin[new[i]])