

#시간 초과;; 나중에 다시 풀자

import sys

def gcd(a,b):

   
    n=a%b
    
    if(n==0):
        return b
    else:
        return gcd(b,n)

N=int(sys.stdin.readline())


num=[]
for i in range(0,N):
    a=int(sys.stdin.readline())
    num.append(a)

num=sorted(num)
new=[]

for i in range(0,N):
    for a in range(0,N):
        if(i!=a):
            if(num[i]-num[a] not in new):
                new.append(abs(num[i]-num[a]))

new=list(set((new)))
base=new[0]

for i in range(1,len(new)):
    base=abs(gcd(base,new[i]))



ans=[]


for i in range(1,int(base**0.5)+1):
    if(base%i==0):
        if(i!=1):
            ans.append(i)
        if(base//i not in ans and base//i!=i):
            ans.append(base//i)


ans=sorted(list(((ans))))

for a in ans:
    print(a,end=" ")    
    


# 12 6 9 69

