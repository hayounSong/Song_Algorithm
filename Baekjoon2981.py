

#시간 초과;; 나중에 다시 풀자

import sys

N=int(sys.stdin.readline())

num=[]
max=0

for i in range(0,N):
    A=int(sys.stdin.readline())
    if(max==0 or A>max):
        max=A
    num.append(A)

ans=[]
for i in range(2,int(max**0.5)+1):
    count=0
    set=num[0]%i
    for a in range(0,len(num)):
        if(num[a]%i!=set):
            count=count+1
            break
    if(count==0):
        ans.append(i)

for i in range(0,len(ans)):
    print(ans[i],end=" ")
