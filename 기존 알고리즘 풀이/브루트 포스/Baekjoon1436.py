import sys


num=666
N=int(sys.stdin.readline())
ans=0


while(True):
    if("666" in str(num)):
        ans=ans+1
    if(ans==N):
        break;
    num=num+1

print(num)
