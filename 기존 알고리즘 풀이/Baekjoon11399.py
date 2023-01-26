import sys

N=int(sys.stdin.readline())

A=sys.stdin.readline().strip().split(" ")
A=list(map(int,A))

A=sorted(A)

count=[0]*N

count[0]=A[0]

for i in range(1,len(A)):
    count[i]=count[i-1]+A[i]

ans=0

for A in count:
    ans=ans+A

print(ans)