import sys

N=int(sys.stdin.readline())
count=1
for i in range(1,N+1):
    count=count*i
ans=0
while(count%10==0):
    count=count//10
    ans=ans+1


print(ans)