import sys

N=int(sys.stdin.readline())

A=sys.stdin.readline().split(" ")

A=list(map(int,A))

newlist=[]
countlist=[]
B=sorted(list(set(A)))

dic={B[b]:b for b in range(len(B))}

for i in range(0,N):
    print(dic[A[i]],end=" ")
