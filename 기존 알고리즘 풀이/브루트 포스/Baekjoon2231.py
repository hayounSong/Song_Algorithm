import sys

N=int(sys.stdin.readline())

ans=0
for i in range(1,N):
    sum=0
    am=i
    while(am!=0):
        sum=sum+am%10
        am=am//10
    if(sum+i==N and (i<=ans or ans==0)):
        ans=i

print(ans)