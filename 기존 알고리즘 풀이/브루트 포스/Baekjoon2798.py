import sys

A=sys.stdin.readline().split(" ");

N=int(A[0])
M=int(A[1])

B=sys.stdin.readline().split(" ");

B=list(map(int,B))

max=0
for a in range(0,N):
    for b in range(a+1,N):
        for c in range(b+1,N):
            sum=B[a]+B[b]+B[c]
            if(sum>max and sum<=M):
                max=sum

print(max)