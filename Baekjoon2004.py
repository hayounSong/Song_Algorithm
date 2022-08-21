import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

count=1

for i in range(N-M+1,N+1):
    count=count*i

for i in range(1,N-M+1):
    count=count//i
print(count)
ans=0

while(count%10==0):
    ans=ans+1
    count=count//10

print(ans)

